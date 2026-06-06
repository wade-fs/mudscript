// Room: /open/tendo/room/t08.c
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
 set("short",HIB"崑崙太極殿"NOR);
	set( "build", 46 );
        set("long",@LONG
傳說中的道家聖地太極殿，地上有幅極大的太極圖形( picture)和一塊石
碑(list)。兩旁的牆壁則雕刻一連串的道家神話--盤古開天闢地，共工怒
觸不周山，后羿射日等等知名的故事。雕工細緻非凡。而天道掌門則正坐
在蒲團上閉眼冥思。

LONG);
set("item_desc",([
	"picture" : "用法: 站立於圖形的八個方位(stand 1~8)\n"+
"	1.京城    2.蜀中城  3.平南城  4.中央驛站    \n"+
"	5.凌雲村  6.login處 7.楓林港  8.夜夢小築\n",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"t03",
	"north" : __DIR__"eqroom",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/taoist/master_lu" : 1,
  "/open/tendo/npc/taoist1" : 1,
]));
  set("light_up", 1);
  set("valid_startroom", 1);
	set("cango",1);

  setup();
  call_other("/obj/board/tendo_b","???");
}
void init()
{
	add_action("do_into","stand");
        add_action("do_billing","list");
}

int do_into(string arg)
{
	object who;
	string room;
        who = this_player();

        if(who->query("class")!="taoist")
        return notify_fail("汝非我派中人，不得進入此圖。\n");
    switch(arg)
    {
       case "1":
         room="/open/capital/room/r70";         break;
       case "2":
         room="/open/gsword/room/su3";          break;
       case "3":
         room="/open/ping/room/road4";          break;
       case "4":
         room="/open/center/room/inn";          break;
       case "5":
         room="/open/start/room/s5";            break;
	case "7":
         room="/open/port/room/r3-1";           break;
	case "8":
	room = "/open/dancer/room/cafeteria";	break;
	case "6":
	room = who->query("start_room");     break;
       default:
	}
	if(!room)
		return 1;
	who->move(room);
        tell_room(this_object(),"你看到"+who->query("name")+"進入太極圖中，忽"+
                                "的一聲，人已不見了。\n");
        return 1;
}

 int valid_leave(object me, string dir)
{
  if( dir=="north" )
     if( me->query("family/family_name")!="天道派")
       return notify_fail("只有天道弟子才能進入。\n");
   return ::valid_leave(me,dir);
}

int do_billing(string str)
{
object *user,me,master;
        int i,j;
	switch(str) {
          case "combat_exp" : i = 0; break;
          case "force" : i = 1; break;
          case "master" : i = 2; break;
          default: return notify_fail("使用格式: list <種類>\n"
                                      "經驗值(combat_exp)\n"+
                                      "內力(force)\n"+
                                      "師承(master)\n\n");
        }
        user = users();
        me = this_player();
	user = filter_array(user,"filter_family",this_object());
	j=sizeof(user);
        switch(i) {
	  case 0 : user=sort_array(user,"sort_exp",this_object());
                   str=sprintf(HIG"天道派經驗值排行榜:\n\n"NOR);
                   for(i=0; i<j; i++)
                      str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
                   str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 1 : user=sort_array(user,"sort_force",this_object());
                   str=sprintf(HIG"天道派內力排行榜:\n\n"NOR);
                   for(i=0; i<j; i++)
                      str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
                   str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 2 : str=sprintf(HIG"天道派師徒關係:\n\n"NOR);
	           for(i=0; i<j; i++) {
	              if( user[i]->query("family/master_is_ppl") ) {
	                if( master=find_player(user[i]->query("family/master_id"))) {
	                  if( master->query("name") != user[i]->query("family/master_name"))
		            user[i]->set("family/master_name",master->query("name"));
	                }
	                else {
		          if( master=FINGER_D->acquire_login_ob(user[i]->query("family/master_id"))) {
	                    if( master->query("name") != user[i]->query("family/master_name"))
	                      user[i]->set("family/master_name",master->query("name"));
                            destruct(master);
                          }
	                }
	              }
	              str+=sprintf(HIC"%|20s(%|10s)     師承  %|20s(%|10s)\n"NOR,user[i]->query("name"),user[i]->query("id"),user[i]->query("family/master_name"),user[i]->query("family/master_id"));
	           }
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
        }
        return 1;
}

int filter_family(object family)
{
 if(family->query("family/family_name") == "天道派" && !wizardp(family)) return 1;
 return 0; 
}
int sort_exp(object man1, object man2)
{
 int i,j;
 i = man1->query("combat_exp");
 j = man2->query("combat_exp");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
int sort_force(object man1, object man2)
{
 int i,j;
 i = man1->query("max_force");
 j = man2->query("max_force");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
