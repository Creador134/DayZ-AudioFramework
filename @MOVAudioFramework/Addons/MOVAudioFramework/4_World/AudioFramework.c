enum AudioType
{
    Single = 0,
    Loop
}

class AudioMeta
{
    int m_Range;
	int m_Type;
	
	string m_Sound;
	
	Object m_Object;
    ScriptCallQueue m_Queue;
	EffectSound m_EffectSound;
	
	void AudioMeta()
	{
	}
}

class AudioFramework
{
    ref AudioMeta m_Audio;
    
    void AudioFramework()
    {
        GetRPCManager().AddRPC( "MOVAudioFramework", "Transfer", this, SingeplayerExecutionType.Both );
        
        m_Audio = new AudioMeta();
        
        if (GetGame().IsClient() || !GetGame().IsMultiplayer())
        {        
            m_Audio.m_Queue = GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY); 
        }
    }
    
    void Transfer(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        Param4< Object, string, int, int > data;
        if ( !ctx.Read( data ) ) return;
		
        if( type == CallType.Client )
        {
			Print("<AudioFramework> Client");
			PlayAudioClient(data.param1, data.param2, data.param3, data.param4);
        }
    }

	void OnPlayAudioClient()
	{
		if (m_Audio.m_Type == AudioType.Single)
		{
			m_Audio.m_Object.PlaySound(m_Audio.m_Sound, m_Audio.m_Range);
		}
		if (m_Audio.m_Type == AudioType.Loop)
		{
			m_Audio.m_Object.PlaySoundLoop(m_Audio.m_Sound, m_Audio.m_Range);
		}
	}
	
	void PlayAudioClient(Object l_Object, string l_Sound, int l_Type, int m_Range)
	{
		m_Audio.m_Object = l_Object;
		m_Audio.m_Sound = l_Sound;
		m_Audio.m_Type = l_Type;
		m_Audio.m_Range = m_Range;	
		
		m_Audio.m_Queue.CallLater(OnPlayAudioClient, m_Range, false);    
	}
	
	void PlayAudio(Object l_Object, string l_Sound, int l_Type = AudioType.Single, int m_Range = 0)
	{
		GetRPCManager().SendRPC( "MOVAudioFramework", "Transfer", new Param4< Object, string, int, int >( l_Object, l_Sound, l_Type, m_Range) )
	}

	void StopAudio()
	{
		
	}
}

static ref AudioFramework g_AudioManager;
static ref AudioFramework GetAudioManager()
{
    if ( !g_AudioManager )
    {
         g_AudioManager = new ref AudioFramework();
    }
    
    return g_AudioManager;
}