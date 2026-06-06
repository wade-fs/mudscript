#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","銀針門大廳");
        set("long",@LONG
進到這裡，你幾乎無法想像這裡竟是銀針門的大廳，簡單樸素的裝潢
，簡陋的傢俱和一般的住家沒有兩樣，唯一不同的是，這裡十分的乾淨，
而且散發著耀眼的光芒。通常神醫華陀都在此替人義診，瞧他忙的還挺開
心的，一旁的藥童盯著神醫針灸的手法，如果你有什麼身體上的疑難雜症
，可以請神醫幫你看看，不過看他拿針方式，若被抸上一下，似乎不太好
受，左邊有一塊木板(list)顯示者線上醫生的排行。
LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"eq_room",
        "south":__DIR__"5",          
        "east":__DIR__"1",           
        "west":__DIR__"3",          
        "enter":__DIR__"book",          
        ]) );
  set("objects", ([ /* sizeof() == 2 */
  "/open/doctor/npc/master_tor.c" : 1,
  "/open/doctor/npc/mdboy.c" : 1,
]));
  set("light_up", 1);
  set("valid_startroom", 1);

  setup();
call_other("/obj/board/doctorr_b.c",  "???");
}
int valid_leave(object me, string dir)
{
        if(me->query("class")!="doctor"&&dir=="north")
        return notify_fail("對不起, 裡面是銀針門弟子的聚會之地!!\n");

        return ::valid_leave(me,dir);
}
void init()
{
    object me, ob;
    me = this_player();
    ob = new("/open/doctor/obj/b-mark");

    if(me->query("doctor/start_quest")==1
    && present("master tor",environment(me))
    && !present("book_mark",me)
    && me->query("family/family_name")=="銀針門")
{
	write("華陀把入閣令交給了你，說道：這重要的東西，為何不收好？");
	ob->move(me);
  }
    add_action("do_billing","list");
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
	           str=sprintf(HIG + "銀針門經驗值排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 1 : user=sort_array(user,"sort_force",this_object());
	           str=sprintf(HIG + "銀針門內力排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
                   tell_object(this_player(),str);
		   break;
	  case 2 : str=sprintf(HIG + "銀針門師徒關係:\n\n" + NOR);
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
 if(family->query("family/family_name") == "銀針門" && !wizardp(family)) return 1;
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
