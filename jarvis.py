#AI-POWERED VIRTUAL ASSISSTANT

import win32com.client
import speech_recognition as sr
import pyaudio
import webbrowser
from datetime import datetime
import googletrans
import speech_recognition
import gtts
import playsound
import requests


def takeCommand():
    try:
        r=sr.Recognizer()
        with sr.Microphone() as source:
            r.pause_threshold=0.6
            audio=r.listen(source)
            query=r.recognize_google(audio,language="en-in")
            print(f"User said : {query}")
            return query
    except Exception as ex:
        return takeCommand()


def say(query):
    speaker.Speak(query)


if __name__ =='__main__':
    print('HELLO')
    print('I am Jarvis AI')
    print('How can i assist you...........')
    speaker=win32com.client.Dispatch("SAPI.Spvoice")
    s="Hello this is Jarvis A I  How can i assist you..... "
    speaker.Speak(s)
    try:
        while 1:
            print("Listening...")
            query=takeCommand()
            sites=[["youtube","https://youtube.com"],["wikipedia","https://wikipedia.com"],["google","https://google.com"]]
            for site in sites:
                if f"open {site[0]}".lower() in query.lower():
                    print(f"opening {site[0]} sir...")
                    speaker.Speak(f"opening {site[0]} sir...")
                    webbrowser.open(site[1])
                    
            if "time".lower() in query.lower():
                date_time = datetime.now().strftime("%d %b %Y    |     %I:%M:%S %p")
                print(f"It's {date_time} sir..")
                speaker.Speak(f"It's {date_time} sir...")

            if "language translator".lower() in query.lower():
                while(True):
                    print(f"Language Translator...")
                    speaker.Speak(f"Language Translator...")
                    input_lang="en"
                    output_lang="te"
                    #print(googletrans.LANGUAGES)
                    recognizer=speech_recognition.Recognizer()
                    with speech_recognition.Microphone() as source:
                        print("Speak now")
                        voice=recognizer.listen(source)
                        text=recognizer.recognize_google(voice,language=input_lang)
                        print(text)
                    translator=googletrans.Translator()
                    translation=translator.translate(text,dest=output_lang)
                    print(translation.text)
                    converted_audio=gtts.gTTS(translation.text,lang=output_lang)
                    converted_audio.save("hello.mp3")
                    playsound.playsound("hello.mp3")
                                  
            if "weather".lower() in query.lower():
                api_key = '06a6427bffe64f25b2b133fd5842f332'
                speaker.Speak("Enter the city name")
                location = input("Enter the city name: ")
                complete_api_link = "https://api.openweathermap.org/data/2.5/weather?q=" + location + "&appid=" + api_key
                api_link = requests.get(complete_api_link)
                api_data = api_link.json()
                # create variables to store and display data
                temp_city = ((api_data['main']['temp']) - 273.15)
                weather_desc = api_data['weather'][0]['description']
                hmdt = api_data['main']['humidity']
                wind_spd = api_data['wind']['speed']
                date_time = datetime.now().strftime("%d %b %Y | %I:%M:%S %p")
                #the print block
                print("-------------------------------------------------------------")
                print("-------------------------------------------------------------")
                print("Weather Stats for - {}  || {}".format(location.upper(), date_time))
                print("-------------------------------------------------------------")
                print("-------------------------------------------------------------")
                print("Current temperature is: {:.2f} deg C".format(temp_city))
                speaker.Speak(f"The temperature is {format(temp_city)} sir...")
                print("Current weather desc  :", weather_desc)
                print("Current Humidity      :", hmdt, '%')
                print("Current wind speed    :", wind_spd, 'kmph')
                print("====================================================")

    except Exception as ex1:
        takeCommand()     