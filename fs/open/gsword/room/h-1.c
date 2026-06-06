inherit ROOM;

void create()
{
   set("short","石室");
   set("long",@LONG
這裡是當年鄭士欣閉關研究武學所建成的石室，在這四周的牆壁上，
刻了無數的人形，每個人形都有著不同的姿勢，像是在舞劍一般，當你注
視著這些人形時，猶如望見鄭士欣的身影一般，所用武功皆是驚世之武學
，令你不禁拔起了劍，隨著那身影舞動了起來，不知不覺間，你的劍法已
更上一層樓。
 

LONG);
  
   set("exits", ([ /* sizeof() == ? */
   "leave" : "/open/gsword/room/h-3.c",
   ]));
   
   set("valid_startroom", 1);
   set("no_clean_up",1);
       set("no_transmit", 1);


set("objects", ([ /* sizeof() == 1 */
   "/open/gsword/npc1/yan" :1,
]));
   set("light_up",10);
   setup();
}
      
