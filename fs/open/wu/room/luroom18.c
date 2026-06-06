// Room: /open/wu/room/luroom17.c
// 瀧山武館的大廳
//更新pass指令為當前recall的房間 by blazakira 2011/5/30

#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "瀧山武館大廳");
  set( "build", 134 );
  set ("long", @LONG
                 ◣                        ◢
                   ║■■■■■■■■■■■■■■║
                ◢═════════════════◣
                 ║田田║田田║  田田  ║田田║田田║
        ◢■■■■■■■■■■■■■■■■■■■■■■■■■◣
         ▕════════════════════════▏
          ▔█田田田田田田  我  武  維  揚  田田田田田田█▔
             █|田田田田田田田田田田田田田田田田田田田|█
              █│     ∥∥                 ∥∥      █
              █│ 田  ║║ 田 │▉▉│ 田  ║║  田  █
              █│     ▉▉    │▉▉│     ▉▉      █

這是瀧山武館大廳大廳的左首有一佈告(sign)和一塊木板(list)，挑高四
米二，雕樑畫棟，裝飾華麗，五張太師椅位於上首，居中的太師椅坐著一
位威嚴的老者，正以銳利的目光盯著你，他便是館主－－任正晴...
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
    "sign" : "
            瀧山武學(lungshan) help lungshan
            浩日心法(haoforce) help haoforce
            烈日護身氣勁(fire-kee) help fire-kee
      
      ",
  ]));
  set("exits", ([ /* sizeof() == 3 */
    "west" : __DIR__"luroom17",
    "south" : __DIR__"luroom21",
    "east" : __DIR__"luroom19",
  ]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
    "/daemon/class/fighter/master_jen" : 1,
  ]));
  set("valid_startroom", 1);

  setup();
  call_other("/obj/board/lungshan_b.c","???");
}

int valid_leave(object me, string dir)
{
  if(me->query("family/family_name")!="瀧山派"&&dir=="south")
    return notify_fail("只有瀧山弟子才能進!\n");
  return ::valid_leave(me,dir);
}

void init()
{
  add_action("do_pass","pass");
  add_action("do_billing","list");  
}

int do_pass()
{
  object me;
  me = this_player();
//  me->move("/open/center/room/inn");
  me->move("/open/common/room/inn"); //更新日期為2011/5/30 by blazakira
  return 1;
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
      str=sprintf(HIG"瀧山派經驗值排行榜:\n\n"NOR);
      for(i=0; i<j; i++)
        str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
      str+="\n";
      tell_object(this_player(),str);
      break;
    case 1 : user=sort_array(user,"sort_force",this_object());
      str=sprintf(HIG"瀧山派內力排行榜:\n\n"NOR);
      for(i=0; i<j; i++)
        str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
      str+="\n";
      tell_object(this_player(),str);
      break;
    case 2 : str=sprintf(HIG"瀧山派師徒關係:\n\n"NOR);
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
  if(family->query("family/family_name") == "瀧山派" && !wizardp(family)) return 1;
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
