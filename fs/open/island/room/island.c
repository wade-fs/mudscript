inherit ROOM;

void create()
{  
   
   set("short","神仙港渡口");
   set ("long", @LONG
在你眼前的是一望無際的沙灘，深藍色天空橫過
一道七彩的虹，四周的景色均是中原所難見到，地上
盡是奇花異草，在白色的瑩瑩沙粒中顯得格外的豔麗
芬芳．                     
LONG);
   set("light_up", 1);
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */
  
    "east" : "/open/island/room/i1",
  "southeast" : "/open/island/room/i5",
]));
   set("outdoors", "/open/main");

 setup();
}
 init()
{
       add_action("board_ship","board");
        do_start_ship();

}
void do_start_ship()
{
        object ob1;
        if(!find_object("boat man"))
        {
        ob1=new("/open/island/npc/bman1");
         ob1->move("/open/island/room/boat1");
        destruct(ob1);
        }
} 
int board_ship(string str)
{
object ob;
        if(!str)
        return notify_fail("你要搭什麼?\n");
        if(!objectp(ob=present(str,environment(this_player()))))
        return notify_fail("看清楚點 , 有那種船嗎 ?\n");
        if(str=="boat") 
        {
        message_vision("$N走到岸邊 , 跳上了小船 !\n",this_player());
        this_player()->move("/open/island/room/boat1");
        return 1;
        }

return 0;
}



