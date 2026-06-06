inherit ROOM;

void create()
{  
   
   set("short","東津港偏口");
   set ("long", @LONG
這是一個新建起來的港口，是前次東瀛入侵時所遺
留下來的，現在已不做為軍事用途，反而成為中原人士
朝外冒險的起點，泊此的小船是到海外小島的唯一方法．
                     
LONG);
   set("light_up", 1);
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/island/room/port",
]));
  
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



