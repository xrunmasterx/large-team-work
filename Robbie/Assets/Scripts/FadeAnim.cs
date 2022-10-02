using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FadeAnim : MonoBehaviour
{
    Animator anim;
    int faderID;
    private void Start()
    {
        anim = GetComponent<Animator>();
        faderID = Animator.StringToHash("Fade");
        GameManager.RegisterSceneFade(this);

    }
    public void FadeOut()
    {
        anim.SetTrigger(faderID);
    }
}
