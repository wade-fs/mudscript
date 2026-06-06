// Room: /open/badman/room/r1
//調整敘述為當前的惡人發展型態 by blazakira 2011/10/11

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "惡人谷大廳");
  set( "build", 19 );
  set ("long", @LONG
這裡就是惡人谷的最高指揮處所，眼前大廳中央擺了九張披著
虎皮的豪華大椅和一塊木板(list)，不過現在只有中間的椅子上坐
了一個人，想必他就是惡人谷的首領了吧。不過說也奇怪，這惡人
谷不是傳說有十大惡人嗎？怎麼大廳中卻只有九張椅子呢....

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "up" : __DIR__"wizroom",
    "north" : __DIR__"eqroom",
    "east" : __DIR__"b7",
  ]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
    "/daemon/class/bandit/master_du.c" : 1,
  ]));
  set("valid_startroom", 1);

  setup();
  call_other("/obj/board/bad_b", "???");
}

int valid_leave(object who, string dir)
{
  if( dir=="up" && !wizardp(who) )
    return notify_fail("樓上為惡人wiz會議室，不過目前閒置中，有關惡人發展的構想可在此處post建議，謝謝。\n");
  if(dir=="north"&&who->query("class")!="bandit")
    return notify_fail("不是惡人谷的弟子無法進去。\n");
  return ::valid_leave(who, dir);
}

void init()
{
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
    case 0 :
      user=sort_array(user,"sort_exp",this_object());
      str=sprintf(HIG + "惡人谷經驗值排行榜:\n\n" + NOR);
      for(i=0; i<j; i++)
        str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
      str+="\n";
      tell_object(this_player(),str);
      break;
    case 1 :
      user=sort_array(user,"sort_force",this_object());
      str=sprintf(HIG + "惡人谷內力排行榜:\n\n" + NOR);
      for(i=0; i<j; i++)
        str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
      str+="\n";
      tell_object(this_player(),str);
      break;
    case 2 :
      str=sprintf(HIG + "惡人谷師徒關係:\n\n" + NOR);
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
  if(family->query("family/family_name") == "惡人谷" && !wizardp(family)) return 1;
  return 0; 
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

int sort_exp(object man1, object man2)
{
  int i,j;
  i = man1->query("combat_exp");
  j = man2->query("combat_exp");
  if (i>j) return -1;
  else if (i<j) return 1;
  else return 0;
}
