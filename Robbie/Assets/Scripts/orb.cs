using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class orb : MonoBehaviour
{
    public GameObject explosion;
    int playersign;
    // Start is called before the first frame update
    void Start()
    {
        GameManager.RegisterOrb(this);
        playersign = LayerMask.NameToLayer("player");
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.layer==playersign)
        {
            Instantiate(explosion, transform.position, transform.rotation);
            gameObject.SetActive(false);
            GameManager.PlayerTouchOrbs(this);
            AudioManager.PlayOrbAudio();
        }
    }
}
