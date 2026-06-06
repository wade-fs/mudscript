

inherit ROOM;
void create()
{
  set ("short", "大長廊");
  set ("long","
    這一長廊四面塗金﹐一路望過去都是金光閃閃﹐像似
要通往哪個重要的地方﹐一路上都是純金打鑄的裝飾品﹐
大都是中國文化的東西莫非這就是他們所謂的戰利品嗎??
往下走去探探究竟吧!!

 ");
   set("exits", ([
   "north"       :__DIR__"r17.c",
   "south"       : __DIR__"r24.c",
   "west"       : __DIR__"r32.c",   
  ]));      
  set("objects", ([ /* sizeof() == 1 */
    "/open/soldier/npc/ma2":1,
]));
  set("light_up", 1);
  setup();
} 

