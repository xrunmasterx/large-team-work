using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public int Orbnum;
    public int DeathTime;
    static GameManager instance;
    FadeAnim fader;
    List<orb> orbs;
    Door lockedDoor;

    private void Awake()
    {
        if (instance != null) 
        {
            Destroy(gameObject);
            return;
        }
        instance = this;
        orbs = new List<orb>();
        DontDestroyOnLoad(this);
    }

    private void Update()
    {
        instance.Orbnum = instance.orbs.Count;
    }
    public static void RegisterSceneFade(FadeAnim obj) 
    {
        instance.fader = obj;
    }
    public static void RegisterOrb(orb orbx)
    {
        if (!instance.orbs.Contains(orbx))
            instance.orbs.Add(orbx);
    }
    public static void DoorAni(Door x)
    {
        instance.lockedDoor = x;
    }
    public  static void PlayerTouchOrbs(orb orbd)
    {
        if (!instance.orbs.Contains(orbd))
            return;
        instance.orbs.Remove(orbd);
        if (instance.orbs.Count == 0)
            instance.lockedDoor.Open();
    }
    public static void PlayerDied()
    {
        instance.fader.FadeOut();
        instance.Invoke("RestartScene", 1.5f);
    }

    void RestartScene()
    {
        instance.orbs.Clear();
        instance.DeathTime++;
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
    }
}
