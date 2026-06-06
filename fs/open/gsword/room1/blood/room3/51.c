#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short",HIC + "開天三才陣陣眼" + NOR);
set ("long", @LONG
這裡是傳說中封印血魔之開天三才陣陣心，定眼一看，在你眼前你看到開天三靈器之光影，光影形成一三角狀，在三角封印中央，似乎包著一個人，他看起來血肉糢糊似乎無比虛弱。
LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/npc1/cking" : 1,
]));
  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 2 */
"back":"/open/common/room/inn.c",
]));
  set("no_transmit", 1);
  setup();
}

void init()
{
add_action("do_search","search");
add_action("do_check","put");
}
int do_search(string str)
{
  object ob;
  ob=this_player();
message_vision("
你定睛一看，此人似乎是在仙劍凌霄寶殿壁畫上的血魔，在向左右晃了晃你發現三靈器劍靈中各有一個圓形孔洞，似乎可以放上什麼東西。\n",ob);
  return 1;
}

int do_check(string str)
{
 mapping weapon = ([
 "swordball in sun_fire_sword" : 1,
 "bladeball in bird-blade" : 2,
 "penball in liyu_pen" : 3,
 "bbladeball in bird-blade" : 4,
 "lpenball in liyu_pen" : 5,
 ]);
 object ob=this_player();
 object ob1;
 string name,str1,str2;
 if (ob->query("class")!="swordsman")
  message_vision("血魔道 : 請將晶珠交給劍客\n",ob);
 else if( !str || sscanf(str, "%s %s", str1, name) != 2 )
  {
   message_vision("請 put xxx in xxx\n",ob);
  }
 else if(weapon[str] && ob->query("class")=="swordsman")
  {
   if(weapon[str]==1)
   {
    if(!present("swordball",ob)) message_vision(HIW + "你將放啥阿\n" + NOR,ob);
 else
 {
   ob->set_temp("su1",1);
   message_vision(HIW + "你將靈珠置入三靈器中.頓時整個房間喀然作響\n" + NOR,ob);
        destruct(present("swordball",ob));
   }
   }
   if(weapon[str]==2)
   {
    if(!present("bladeball",ob)) message_vision(HIW + "你將放啥阿\n" + NOR,ob);
 else
 {
   ob->set_temp("su2",1);
   ob->set("swordskill/fsword3",1);
   message_vision(HIW + "你將靈珠置入三靈器中.頓時整個房間喀然作響\n" + NOR,ob);
        destruct(present("bladeball",ob));
   }
   }
   if(weapon[str]==3)
   {
    if(!present("penball",ob)) message_vision(HIW + "你將放啥阿\n" + NOR,ob);
 else
 {
    ob->set_temp("su3",1);
    ob->set("swordskill/fsword4",1);
   message_vision(HIW + "你將靈珠置入三靈器中.頓時整個房間喀然作響\n" + NOR,ob);
        destruct(present("penball",ob));
   }
   }
   if(weapon[str]==4)
   {
    if(!present("bbladeball",ob)) message_vision(HIW + "你將放啥阿\n" + NOR,ob);
 else
 {
    if( present("bbladeball",ob)->query("bloodcheck")==1 )
     {
       ob->set_temp("su2",1);
       ob->set("swordskill/sword3",1);
       message_vision(HIW + "你將靈珠置入三靈器中.頓時整個房間喀然作響\n" + NOR,ob);
       destruct(present("bbladeball",ob));
     }
    else
     {
       message_vision(HIW + "你拿什麼東西魚目混珠阿....給我死出去\n" + NOR,ob);
       ob->move("/open/common/room/inn.c");
     }
   }
 }
   if(weapon[str]==5)
   {
    if(!present("lpenball",ob)) message_vision(HIW + "你將放啥阿\n" + NOR,ob);
 else
 {
   if( present("lpenball",ob)->query("bloodcheck")==1 )
   {
    ob->set_temp("su3",1);
    ob->set("swordskill/sword4",1);
    message_vision(HIW + "你將靈珠置入三靈器中.頓時整個房間喀然作響\n" + NOR,ob);
    destruct(present("lpenball",ob));
   }
    else {
     message_vision(HIW + "你拿什麼東西魚目混珠阿....給我死出去\n" + NOR,ob);
       ob->move("/open/common/room/inn.c");
   }
  }
  }
  }
 else
  {
   message_vision(HIW + "你觸動機關-三靈器發出一到耀眼的光芒!!!\n" + NOR,ob);
   ob->unconcious();
   return 0;
  }
 if(ob->query_temp("su1")==1&&ob->query_temp("su2")==1&&ob->query_temp("su3")==1)
  {
   log_file("sword/blood",sprintf("%s(%s) free bloodking on %s\n",ob->query("name"),ob->query("id"),ctime(time()) ));
   tell_object(users(),HIC + "血魔狂笑道 : 哈哈~~總算有人破解仙劍老賊的陣法啦！！\n\n" + NOR,ob);
   ob1 = present("bloodking",this_object());
   destruct(ob1);
   call_out("msg1",3,ob);
   return 1;
  }
}


int msg1(object ob)
{
   tell_object(users(),HIY + "血魔大喝 :" + HIR + " 魔威蕩蕩聖佛懼，血霧濛濛神魔震！\n\n" + NOR,ob);
   tell_object(users(),HIR + "           眾血魔將，聽我號令，血染武林！\n\n" + NOR,ob);
   new("/open/gsword/npc2/bknight")->move("/open/capital/room/r70");
   new("/open/gsword/npc2/bknight")->move("/open/capital/room/r70");
   new("/open/gsword/npc2/bknight")->move("/open/gsword/room/su3");
   new("/open/gsword/npc2/bknight")->move("/open/gsword/room/su3");
   new("/open/gsword/npc2/bknight")->move("/open/ping/room/road4");
   new("/open/gsword/npc2/bknight")->move("/open/ping/room/road4");
   new("/open/gsword/npc2/bknight")->move("/open/start/room/s5");
   new("/open/gsword/npc2/bknight")->move("/open/start/room/s5");
   new("/open/gsword/npc2/bknight")->move("/open/port/room/r3-1");
   new("/open/gsword/npc2/bknight")->move("/open/port/room/r3-1");
   new("/open/gsword/npc2/bknight")->move("/open/wind-rain/room9");
   new("/open/gsword/npc2/bknight")->move("/open/wind-rain/room9");
   new("/open/gsword/npc2/bknight")->move("/open/prayer/room/westarea/road29");
   new("/open/gsword/npc2/bknight")->move("/open/prayer/room/westarea/road29");
   new("/open/gsword/npc2/bknight")->move("/open/main/room/r5");
   new("/open/gsword/npc2/bknight")->move("/open/main/room/r5");
   new("/open/gsword/npc2/bknight")->move("/open/snow/room/room3");
   new("/open/gsword/npc2/bknight")->move("/open/snow/room/room3");
   new("/open/gsword/npc2/bknight")->move("/open/capital/room/r15");
   new("/open/gsword/npc2/bknight")->move("/open/capital/room/r15");

   call_out("msg2",3,ob);

   return 1;
 }

int msg2(object ob)
{
  object room,obj;
  mixed all;
  int j;
  room = environment(ob);
  all = all_inventory(room);

  message_vision(HIY + "你開封印後，我想也沒辦法回仙劍派了吧，你到魔域來找我，我教你一套威力大於連陽劍法的『血魔霸劍式』。\n" + NOR,ob);
  message_vision(HIY + "不過..因為你當初得到開天三靈器晶珠的過程..威力亦會跟著改變，故..如果無法發揮實力..那就是你的造化了。\n" + NOR,ob);
  ob->set("title",HIW + "Π" + HIR + "魔" + HIC + "亟" + HIY + "劍宗" + HIW + "Π" + NOR);
  ob->set("family/family_name","血魔一派");
  message_vision(HIC + "  ...我在天邪峰盡頭那有個魔堡…你就到那來吧… \n",ob);
  message_vision(HIC + "  ...其他們派的朋友，也歡迎你們來作客 \n",ob);
  ob->set("bloodsword",2);
  ob->set("swordskill/bloodz",1);
  ob->set("return",1);
  ob->set("highsworder",1);
for ( j = 0 ; j < sizeof(all) ; j++)
{
  obj = all[j];
  if (obj->is_character() && !obj->is_corpse() && living(obj))
     {
      obj->set("highsworder",1);
     }
 }

  return 1;

}

