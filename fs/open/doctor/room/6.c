#include <room.h>
inherit ROOM;
string search();
void create()
{
        set("short", "藥房");
        set("long", @LONG

    房間裡擺滿了藥櫃，此處便是銀針門儲藥的地方，華陀也常常吩
咐弟子們來此抓藥，因為這裡有些稀世罕見的草藥，所以通常這裡有
藥童在此看守，沒事最好別待在這，以免被誤會為賊。

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"3",            
        "south":__DIR__"9",          
        "east":__DIR__"5",          
        ]) );
        set("light_up", 1);
         set("objects", ([ /* sizeof() == 1 */
  "/open/doctor/npc/mdguard.c" : 1,
]));

   setup();
 set("search_desc", ([ /* sizeof() == 1 */
  "藥櫃" : (: search :),
]));
  setup();
}


string search()
{
if (this_player()->query_temp("shaswordtime")==1)
{
   message_vision("$N在藥櫃中找來找去 , 摸出了一顆土法珠並收進口帶中 \n",this_player() );
   this_player()->set_temp("quests/findball5",1);
   new("/open/gsword/obj1/soilball")->move(this_player());
   return "";
  }
        message_vision("$N在這翻來覆去 , 結果什麼也沒發現 \n",this_player());
        return "";
}
