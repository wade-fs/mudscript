inherit ROOM;
#include <ansi.h>
#include "room.msg"

void create () {
        set ("short","玄武幻陣");
        set ("long",
        (: print_room_msg :)
        );
    
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
        "北門" : __DIR__"room7",
        "南門" : __DIR__"room2",
        "東門" : __DIR__"room6",
        "西門" : __DIR__"room9",
        ]));

        set("objects",([ /* sizeof() == 1 */
        __DIR__"npc/beast" : 1,
        ]));

        setup();
}
void init()
{	
  call_out("do_exit",1,this_player()); 
}
void do_exit(object me)
{      
       int cor;
       set("exits", ([ /* sizeof() == 1 */
        "北門" : __DIR__"room7",
        "南門" : __DIR__"room2",
        "東門" : __DIR__"room6",
        "西門" : __DIR__"room9",
        ]));
      cor=me->query_cor();
      if(me->query("setgift-mk")==1)
        cor=me->query("setgift/cor");                    
      if(cor>30)
        cor=30;
      switch(random(100))
      {
      	case 0..24:
      	if(100<(random(100)+me->query_cor()))
          set("exits/北門", __DIR__"room16");
        break;
        
        case 25..49:
      	if(100<(random(100)+me->query_cor()))
          set("exits/南門", __DIR__"room16");
        break;
        
        case 50..74:
      	if(100<(random(100)+me->query_cor()))
          set("exits/西門", __DIR__"room16");
        break;
        
        case 75..100:
      	if(100<(random(100)+me->query_cor()))
          set("exits/東門", __DIR__"room16");
        break;
        }
      me->set_temp("exit_ok",1);
}
int valid_leave(object who, string dir)
{
        int i;
        object *inv;
        if (dir == "北門" || dir == "南門" || dir == "西門" || dir == "東門")
        {
                if(!who->query_temp("exit_ok",1))
                  return notify_fail(HIY + "玄武幻陣正在變換陣形，你最好不要輕舉妄動!!\n" + NOR);     
                who->delete_temp("exit_ok",1);
                inv = all_inventory(environment(who));
                for(i=0;i<sizeof(inv);i++)
                {
                  if(userp(inv[i]) || living(inv[i]) || inv[i]->query("capacity")) continue;
                  destruct(inv[i]);
                }
        }
        return :: valid_leave(who,dir);        
}

