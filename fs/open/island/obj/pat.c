#include <ansi.h>
// by airke
inherit NPC;

void do_sleep();

void create()
{ 
  set_name(HIY"小黃金甲龍"NOR,({"gold-dragon","dragon"}));
  set("age",1);
  set("long","pat it or order <動作>\n");
  set("no_kill",1);
  set("kee",200000);
  set("max_force",10000);
  set("force_factor",30);
  set("combat_exp",7000000);
  set("chat_chance", 35);
  set("chat_msg", ({
  HIY+"黃金小甲龍高興的在你身旁繞來繞去～～～\n"NOR,
  HIY+"黃金小甲龍眨了眨大大的雙眼，很無辜的望著你....\n"NOR,
  HIY+"黃金小甲龍大吼: ㄚ～～～～ㄨ～～～～\n"NOR,
  HIY+"黃金小甲龍用腳在地上無聊地畫著圈圈....\n"NOR,
  HIY+"黃金小甲龍伸手一指，變出了一堆食物........開始躲在一旁大快朵頤 :D~~\n"NOR,
  HIY+"黃金小甲龍爬到你肩上舔了舔你的臉。哇！....好噁心ㄛ..\n"NOR,     
  HIY+"黃金小甲龍依偎在你腳邊撒嬌。\n"NOR,
  HIY+"黃金小甲龍很累地打了一個哈欠...Zzzz\n"NOR,
  (: do_sleep :),
  }));

  setup();
}

void do_follow(object owner)
{
 command("follow "+owner->query("id")); 
 set_leader(owner);
return;
}

void init() {
object obj;
::init();
     if(interactive(obj=this_player())) {
          command("ssmile "+obj->query("id"));
        }
add_action("do_pat","pat");
add_action("do_order","order");
add_action("do_kick","kick");
add_action("do_lick","lick");
add_action("do_flop","flop");
add_action("do_die","die");
add_action("do_faint","faint");
add_action("do_hammer","hammer");
add_action("do_spit","spit");
add_action("do_ride","ride");
add_action("do_shout","shout");
return;
}

int do_pat(string str) {
 
  object scale,room;
  string name;

  if(!str||sscanf(str, "%s",name)!=1)
          return 0;
  if(name != "gold-dragon")
          return 0;
  message_vision (HIC"$N拍拍黃金小甲龍的頭，黃金小甲龍又變成了木雕。\n"NOR,this_player());
  room = environment(this_player());
  new("/open/island/obj/statue")->move(room); 
  destruct(this_object());
  return 1;
}


int do_order(string str)
{
  string act,tar;  
  
 if(this_player()!=this_object()->query_leader())
       return 0;
  if(!str)
       return notify_fail(HIY"黃金小甲龍眨了眨雙眼，疑惑地望著你....\n"NOR);
  if(sscanf(str, "%s %s",act,tar)==2) {
     command(act+" "+tar);
     return 1;
  }
  if(sscanf(str, "%s",act)) {
     command(act);
     return 1;
  }
 return 1;
}

void do_sleep()
{
  object room;
  mixed all;
  int allnum,i; 

  room = environment(this_object());
  all = all_inventory(room);
  allnum=sizeof(all);
  for(i=0;i<allnum;i++) {
      if(userp(all[i])) {
          message_vision (HIY"小甲龍偷偷鑽進了$N的懷裡....睡著了....\n"NOR,all[i]);
          new("/open/island/obj/spat")->move(all[i]);
          i=allnum+1;              
      }
  } 
  destruct(this_object());
 return;
}

int do_ride(string str) {
 
  object room;
  string name;

  if(!str||sscanf(str, "%s",name)!=1)
          return 0;
  if(name != "gold-dragon")
          return 0;

  command("inn");
  write("\n牠還沒滿周歲ㄝ，請愛護稀有動物....\n");
  
  return 1;
}



