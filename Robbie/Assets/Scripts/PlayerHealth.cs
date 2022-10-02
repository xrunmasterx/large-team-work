using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class PlayerHealth : MonoBehaviour
{
    int trapssign;
    public GameObject deathVFXprefab; 
    // Start is called before the first frame update
    void Start()
    {
        trapssign = LayerMask.NameToLayer("traps");

    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.gameObject.layer==trapssign)
        {
            Instantiate(deathVFXprefab, transform.position, transform.rotation);
            gameObject.SetActive(false);
            AudioManager.PlayDeathAudio();

            //SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);

            GameManager.PlayerDied();
        }
    }
}
