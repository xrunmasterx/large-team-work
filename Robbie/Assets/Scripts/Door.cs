using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Door : MonoBehaviour
{
    Animator doora;
    // Start is called before the first frame update
    void Start()
    {
       doora= GetComponent<Animator>();
        GameManager.DoorAni(this);
    }

    public  void Open()
    {
        doora.SetTrigger("Open");
    }

}
