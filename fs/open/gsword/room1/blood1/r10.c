#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "血魔殿");
	set( "build", 28 );
  set ("long", @LONG
此處為血魔堡之最深處，四周所見皆為血色，地上的血跡一路指向房裡的最上方
你沿血跡向上看，只見血魔坐在殿上的座椅上..一附心機重重的樣子，似乎已等你很
久了..，左邊有一塊血版(list)記錄血魔弟子的排行。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room1/blood1/r5.c",
//  "south" : "/open/gsword/room1/blood1/r9.c",
//  "east" : "/open/gsword/room1/blood1/r5.c",
//  "west" : "/open/gsword/room1/blood1/r5.c",
]));

  set("light_up", 1);
  set ( "no_transmit", 1 );
  set("objects", ([ /* sizeof() == 1 */
   "/open/gsword/npc1/bloodking" :1,
]));


  setup();
call_other("/obj/board/appoblood_b","???");
}
void init()
{
  object who;
  add_action("do_verify","take");
  if( interactive( who= this_player()))
   {
      remove_call_out("greeting");
        call_out("greeting", 0, who);
   }
  add_action("do_billing","list");  
}
int do_verify(string arg)
{
 object me,ob;
 me=this_player();
 ob=new("/autoload/swordsman/bloodbook");
 if( arg!="bloodbook")
{
    write("你要申請什麼\n");
    return 1;
   }
if(!me->query("highsword") && me->query("bloodsword")!=2)
  {
    write("你拿了這東西也沒用\n");
    return 1;
  }

 if( present(ob,me) )
  {
    write("你已經有一本了\n");
    return 1;
   }
   else
    {
     write("好好保管此書, 別再弄丟了.\n");
     ob->move(me);

     return 1;
    }
}
int greeting (object who)
{
 if (who->query_temp("ko_yan")==1 && who->query("swordskill/sword5")!=1 )
 {
 message_vision(HIY + "血魔狂笑道：幹的好阿，你竟有法殺的了風青雲，來我教你血魔殺法水之技的精華。\n" + NOR,who);
  if( (who->query("potential") - who->query("learned_points"))<100000)
{
    message_vision(HIY + "但$N潛能不足，無法領會箇中奧妙。\n" + NOR,who);
    }
else
  {
    message_vision(HIY + "$N廢盡心力，照著血魔的指導演練了一便。\n" + NOR,who);
    who->set("swordskill/sword5",1);
    who->add("learned_points",100000);
    who->delete_temp("ko_yan",);
  }
 }
else if (who->query_temp("ko_tian")==1 && who->query("swordskill/sword6")!=1 )
 {
 message_vision(HIY + "血魔狂笑道：幹的好阿，你竟有法殺的了鳳祥天，來我教你血魔殺法炎之技的精華。\n" + NOR,who);
  if( (who->query("potential") - who->query("learned_points"))<100000)
{
    message_vision(HIY + "但$N潛能不足，無法領會箇中奧妙。\n" + NOR,who);
    }
else
{
 message_vision(HIY + "$N廢盡心力，照著血魔的指導演練了一便。\n" + NOR,who);
 who->set("swordskill/sword6",1);
 who->add("learned_points",100000);
 who->delete_temp("ko_tian",);
 }
}
else if (who->query_temp("ko_yao")==1 && who->query("swordskill/sword7")!=1 )
 {
 message_vision(HIY + "血魔狂笑道：幹的好阿，你竟有法殺的了逍遙子，來我教你血魔殺法奧義嵐之技的精華。\n" + NOR,who);
  if( (who->query("potential") - who->query("learned_points"))<150000)
  {
    message_vision(HIY + "但$N潛能不足，無法領會箇中奧妙。\n" + NOR,who);
    }
   else
   {
     message_vision(HIY + "$N廢盡心力，照著血魔的指導演練了一便。\n" + NOR,who);
     who->set("swordskill/sword7",1);
     who->add("learned_points",150000);
     who->delete_temp("ko_yao",);
   }
  }

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
	           str=sprintf(HIG + "血魔一派經驗值排行榜:\n\n" + NOR);
                   for(i=0; i<j; i++)
                      str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
                   str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 1 : user=sort_array(user,"sort_force",this_object());
                   str=sprintf(HIG + "血魔一派內力排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 2 : str=sprintf(HIG + "血魔一派師徒關係:\n\n" + NOR);
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
	              str+=sprintf(HIC + "%|20s(%|10s)     師承  %|20s(%|10s)\n" + NOR,user[i]->query("name"),user[i]->query("id"),user[i]->query("family/master_name"),user[i]->query("family/master_id"));
	           }
	           str+="\n"; 
	           tell_object(this_player(),str);
		   break;
        }
        return 1;
}
int filter_family(object family)
{
 if(family->query("family/family_name") == "血魔一派" && !wizardp(family)) return 1;
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
