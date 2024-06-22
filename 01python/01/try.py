from gtts import gTTS
import vlc
myobj = gTTS(text="صباح الفل", lang= 'ar', slow = False)
myobj.save("welcome.mp3")
