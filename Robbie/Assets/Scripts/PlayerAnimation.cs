using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerAnimation : MonoBehaviour
{
    Animator anim;
    PlayerMovement movement;
    Rigidbody2D rb;



    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>();
        movement = GetComponentInParent<PlayerMovement>();
        rb = GetComponentInParent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()   
    {
        anim.SetFloat("speed", Mathf.Abs(movement.xVelocity));
        anim.SetBool("isOnGround", movement.isOnGround);
        anim.SetBool("isJumping", movement.isJump);
        anim.SetBool("isCrouching", movement.isCrouch);
        anim.SetBool("isHanging", movement.isHanging);
        anim.SetFloat("verticalVelocity", rb.velocity.y);
    }


    public void StepAudio()
    {
        AudioManager.PlayFootstepAudio();
    }

    public void CrouchStepAudio()
    {
        AudioManager.PlayCrouchFootstepAudio();
    }

}
