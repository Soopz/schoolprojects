import tweepy
# Authenticate to Twitter
auth = tweepy.OAuthHandler("dEcxKsTr2AT0LFTPudw1EHDKO", "bvNM9So78PqkLSKF4hX8ID1fjFBdxA1LPEfVg1HVEWpUFvI1E0")
auth.set_access_token("628860813-uFF3V6KCzwc00UkK5W081cvzrGFaRFZrqCbU77TB", 
    "QdMk1MxF2zEdcsMp1gAVlTzOWh4zO2Jdi1cPVtKa9I15G")

api = tweepy.API(auth)

try:
    api.verify_credentials()
    print("Authentication OK")
except:
    print("Error during authentication")