
inherit ROOM;
void create()
{
  set ("short", "大長廊");
  set ("long","
    這一長廊四面塗金﹐一路望過去都是金光閃閃﹐像似
要通往哪個重要的地方﹐一路上都是純金打鑄的裝飾品﹐
大都是中國文化的東西莫非這就是他們所謂的戰利品嗎??
右邊的路好像有人在開會一樣。。。

 ");
   set("exits", ([

   "north"       :__DIR__"r24.c",
   "east"       : __DIR__"r28.c",   
  ]));      
  set("light_up", 1);
  setup();
} 


