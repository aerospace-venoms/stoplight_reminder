# stoplight_reminder

## A recurring reminder for meatspace

You know how sometimes you have stuff you need to do in meatspace, like do the laundry, clean the litterbox, or take our your garbage? And you know how it keeps /needing to be done/? If you're anything like me, you've tried recurring reminders on your phone, but those are just missing a little something. Inevitably, you'll be doing something else when the reminder triggers, and you'll snooze or dismiss it. The task will never get done.

Enter: The stoplight reminder.

It's very simple. It has a button. It has some lights. It keeps track of time. And it lives in meatspace, physically next to the thing that needs doing. When it's time to do something, the light turns red. So you do the thing, and push the button, and the light goes back to green again... until inevitably it turns to yellow and back to red, informing you of the inevitable return of the task you need to do.

The thought is that the physical proximity of going to the alarm to turn it off will put you close enough that you may as well just do the task. I think it will work for me. Anyway, this is that. Good luck, have fun. 

## Notes for me about my programming setup:

I'm using stm32f103 "blue pill" modules I bought like 10 years ago in a bulk pack, probably ultimately from taiwan. Hi, Shenzhen city if you can hear me from there. I'd love to visit someday. Anyway, it's a knockoff of a knockoff, but it ought to be good enough for what I want here. Massive overkill. Here are some notes about the settings I'm using.

Programming jumpers: Both towards the USB side of the board.
Push the reset button just before programming.
Program using the unmodified stlink board I have lying around somewhere. I'll know it by the superglued-together 4-wire SWIO jumper I made attached to the end. 
