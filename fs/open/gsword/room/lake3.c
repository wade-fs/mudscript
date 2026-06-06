#include "/open/open.h"

inherit ROOM;
int counter = 10;
void create ()
{
  set ("short", "昆明湖南");
  set ("long", @LONG
這是昆明湖的最南端,蒼蔥的樹木與苔鮮是這裡的要角,
昆明湖水於此向南溢出,一河清水斜躺在樹陰下,鵝白的石子
在水中,更顯得晶盈.你不禁想彎下腰去觸摸(touch)溪水,洗
去你一身的塵埃...
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/mob/squirt" : 1,
  "/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : "/open/gsword/room/lake2",
  "northwest" : "/open/gsword/room/lake0",
]));

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}

void init()
{
     add_action("touch_water","touch");
}
int touch_water(string arg)
{  
   int _gin;
   message_vision("只見一陣煙波從$N身上流過....\n",this_player());
   if( (counter + random(10)) > 10 )
   {
     message_vision("$N覺得全身舒爽....\n\n",this_player());
     this_player()->add("kee",10);
     counter --;
     return 1;
   } else {
      _gin = this_player()->query("gin");
      message_vision("$N覺得全身一陣寒意...\n\n",this_player());
      if( _gin >5 )
      { 
       this_player()->add("gin", -5);
      }else{
       message_vision("$N似乎凍昏了!!\n",this_player());
       this_player()->set("gin", 1);
       this_player()->set("kee", 1);
      }    
      return 1;
   }
}                              
