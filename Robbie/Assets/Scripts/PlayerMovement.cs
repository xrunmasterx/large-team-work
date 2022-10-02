using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    // Start is called before the first frame update

    private Rigidbody2D rb;
    private BoxCollider2D coll;

    [Header("移动参数")]
    public float speed = 8f;
    public float crouchSpeedDivisor = 3f;

    [Header("跳跃参数")]
    public float jumpForce = 5.5f;
    public float jumpHoldForce = 0.15f;
    public float jumpHoldDuration = 0.2f;
    public float crouchJumpBoost = 4f;
    public float hangingJumpForce = 15f;

    float jumpTime;

    [Header("状态")]
    public bool isCrouch;
    public bool isOnGround;
    public bool isJump;
    public bool isHeadBlocked;
    public bool isHanging;

    [Header("环境检测")]
    public float footOffset = 0.4f;
    public float headClearance = 0.5f;
    public float groundDistance = 0.07f;
    float playerHeight;
    public float eyeHeight = 1.5f;
    public float grabDistance = 0.4f;
    public float reachOffset=0.7f;


    public LayerMask groundLayer;

    public float xVelocity;

    //按键设置
    bool jumpPressed;
    bool jumpHeld;
    bool crouchHeld;
    bool crouchPressed;

    //碰撞体尺寸
    Vector2 colliderStandSize;
    Vector2 colliderStandOffset;
    Vector2 colliderCrouchSize;
    Vector2 colliderCrouchOffset;
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        coll = GetComponent<BoxCollider2D>();

        playerHeight = coll.size.y;
        colliderStandSize = coll.size;
        colliderStandOffset = coll.offset;
        colliderCrouchSize = new Vector2(coll.size.x, coll.size.y/2f);
        colliderCrouchOffset = new Vector2(coll.offset.x, coll.offset.y/2f);
    }

    // Update is called once per frame
    void Update()
    {
        jumpPressed = Input.GetButtonDown("Jump");
        jumpHeld = Input.GetButton("Jump");
        crouchHeld = Input.GetButton("Crouch");
        crouchPressed = Input.GetButtonDown("Crouch");
        MidAirMovement();
    }
    private void FixedUpdate()
    {
        
        PhysicsCheck();
        GroundMovement();
        //MidAirMovement();
    }

    void PhysicsCheck()
    {
        Vector2 pos = transform.position;
        Vector2 offsetleft = new Vector2(-footOffset+0.1f, 0f);
        Vector2 offsetright = new Vector2(footOffset-0.1f, 0f);
        Vector2 offsethead = new Vector2(0f,coll.size.y);
      RaycastHit2D leftCheck = Physics2D.Raycast(pos + offsetleft, Vector2.down, groundDistance, groundLayer);
        RaycastHit2D rightCheck = Physics2D.Raycast(pos + offsetright, Vector2.down, groundDistance, groundLayer);
        RaycastHit2D headCheck = Physics2D.Raycast(pos + offsethead, Vector2.up, headClearance, groundLayer);
        Color colorleft = leftCheck ? Color.red : Color.blue;
        Color colorright = rightCheck ? Color.red : Color.blue;
        Debug.DrawRay(pos + offsetleft, Vector2.down, colorleft, 0.2f);
        Debug.DrawRay(pos + offsetright, Vector2.down, colorright, 0.2f);
        Debug.DrawRay(pos + offsethead, Vector2.up, Color.red/*colorhead*/, 0.2f);


        if (/*coll.IsTouchingLayers(groundLayer)*/leftCheck || rightCheck)
        {
            isOnGround = true;
            //isJump = false;
        }
        else isOnGround = false;


        if (headCheck)
            isHeadBlocked = true;
        else isHeadBlocked = false;

        float direction = transform.localScale.x;
        Vector2 grabDir = new Vector2(direction, 0f); ;
        RaycastHit2D blockedCheck = Physics2D.Raycast(pos+new Vector2(footOffset * direction, playerHeight), grabDir, grabDistance,groundLayer);
        Debug.DrawRay(pos+new Vector2(footOffset * direction, playerHeight), grabDir, Color.red/*colorhead*/, grabDistance);
        RaycastHit2D wallCheck = Physics2D.Raycast(pos + new Vector2(footOffset * direction, eyeHeight), grabDir, grabDistance, groundLayer);
        Debug.DrawRay(pos + new Vector2(footOffset * direction, eyeHeight), grabDir, Color.red/*colorhead*/, grabDistance);
        RaycastHit2D ledgeCheck = Physics2D.Raycast(pos + new Vector2(reachOffset * direction, playerHeight), Vector2.down, grabDistance, groundLayer);
        Debug.DrawRay(pos + new Vector2(reachOffset * direction, playerHeight), Vector2.down, Color.red/*colorhead*/, grabDistance);

        if (!isOnGround && rb.velocity.y < 0 && ledgeCheck && wallCheck && !blockedCheck)
        {
            Vector2 pos2 = transform.position;
            pos2.x+= (wallCheck.distance * direction);
            pos2.y -= ledgeCheck.distance;
            transform.position = pos2;

            rb.bodyType = RigidbodyType2D.Static;
            isHanging = true;
        }
    }

    void GroundMovement()    //人物水平移动
    {
        if(isHanging)
        {
            return;
        }
        if (crouchHeld&&!isCrouch&&isOnGround)
            Crouch();
        if (isCrouch&& !crouchHeld&&!isHeadBlocked)
            Standup();
        xVelocity = Input.GetAxis("Horizontal");
        if (isCrouch)
            xVelocity /= crouchSpeedDivisor;
        rb.velocity = new Vector2(xVelocity * speed, rb.velocity.y);
        filpDirction();
    }

    void MidAirMovement()
    {
        if(isHanging)
        {
            if(jumpPressed)
            {
                rb.bodyType = RigidbodyType2D.Dynamic;
                rb.velocity = new Vector2(rb.velocity.x, hangingJumpForce);
                isHanging = false;
            }
            if(crouchPressed)
            {
                rb.bodyType = RigidbodyType2D.Dynamic;
                isHanging = false;
            }
        }



        if(jumpPressed&&isOnGround && !isJump&&!isHeadBlocked)
        {
            if(isCrouch)
            {
                Standup();
                rb.AddForce(new Vector2(0f, crouchJumpBoost), ForceMode2D.Impulse);
            }
            isOnGround = false;
            isJump = true;

            jumpTime = Time.time + jumpHoldDuration;
            //rb.velocity = new Vector2(rb.velocity.x, jumpForce);
            rb.AddForce(new Vector2(0f, jumpForce), ForceMode2D.Impulse);

            AudioManager.PlayJumpAudio();
        }
        else if(isJump)
        {
            if(jumpHeld)
                //rb.velocity = new Vector2(rb.velocity.x, jumpHoldForce);
                rb.AddForce(new Vector2(0f, jumpHoldForce), ForceMode2D.Impulse);
            if (jumpTime<Time.time)
                isJump=false;
        }
    }
    
    void filpDirction()    //人物转身
    {
        if (xVelocity < 0)
            transform.localScale = new Vector3(-1, 1,1);
        if (xVelocity > 0)
            transform.localScale = new Vector3(1, 1,1);
    }

    void Crouch()  //蹲下操作
    {
        isCrouch = true;
        coll.size = colliderCrouchSize;
        coll.offset = colliderCrouchOffset;
    }

    void Standup()   //起立操作
    {
        isCrouch = false;
        coll.size = colliderStandSize;
        coll.offset = colliderStandOffset;
    }
}
