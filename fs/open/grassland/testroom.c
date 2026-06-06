#include <room.h>
inherit ROOM;
void create()
{
        set("short","銀針門大門");
        set("long",@LONG

  眼前是一棟紅磚砌的建築物，座落於這個世外桃源，四周都種滿了奇珍異草
  ，立足之處便聞得一股濃厚的藥味，得其而知裡面就是響譽南方的銀針門了
      　               ┌─────────┐
                 　　　│  仁  心  仁  德  │
                       └─────────┘
                 ┌─┐                     ┌─┐
  　   　　      │挨│    　　　　　　     │救│
  　 　　　      │我│　　    　  　　　　 │人│
  　 　　  　    │一│　　　　      　　　 │一│
     　　　　    │針│　　　　　　    　　 │命│
     　　 　     │  │                     │  │
         　      │免│    　　　　　　　　 │勝│
    　  　　　   │下│　　    　　　　　　 │造│
  　      　　   │十│　　　　    　　　　 │七│
  　　      　   │八│　　　　　　    　　 │級│
  　 　          │地│　　　　　　　　     │浮│
  　 　　        │獄│    　　　　　　　　 │屠│
                 └─┘                     └─┘
LONG);
      set("item_desc", ([ /* sizeof() == 1 */
      "north" : (: look_door,     "north" :),
]));
      set("light_up", 1);

      set("exits", ([ /* sizeof() == 2 */
      "north":__DIR__"26",     
      "south":__DIR__"d3",
        ]) );

        set("objects",([ /* sizeof() == 2 */
        "/open/doctor/npc/guard" : 1,  
        "/open/doctor/npc/guard2" : 1,
]));
        create_door("north","紅木刻紋大門", "south",DOOR_CLOSED);
  setup();
}


