//調整訊息為更加明顯 因為動不動就找wiz來看 有點麻煩 所以凸顯調整訊息 by blazakira 2010/9/26
#include <room.h>
#include <ansi.h>
inherit ROOM;
int done,done1,done2;//作為紀錄是否有人解開過

void create ()
{
    seteuid(getuid()); 
  set ("short",HIC + "封印地" + NOR);
  set ("long", @LONG
在通過密道之後，你眼前出現三座大雕像，地上滿滿的劍痕，隱約可感覺
到一股剛硬之氣；除了三座雕像(statue)之外，還有一個極大的石門，門上貼
了數道古符…似乎在封印著極不祥的東西，門邊有一石碑(stone) ，石碑上好
似刻有東西……

LONG);

 set("item_desc", ([ /* sizeof() == 2*/
  "stone" :"逍遙子封印天魔於此！\n",
  "statue" : "三座古雕像，其中包括了一位劍客(sworder)、刀客(blader)及書生(scholar)。\n不過雕像上似乎都有個痕跡…不知是做什麼用的……\n"]));
 set("exits", ([ /* sizeof() == 1 */
  "back":"/open/common/room/inn.c",
 ]));
 set("no_auc", 1);
 set("no_reset",1);
 set("no_transmit", 1);
setup();
}
void init()
{
 add_action("do_search","search");
 add_action("do_enter","put");
}

int do_search(string str)
{
  object ob,ob1;

  ob=this_player();
  if( str != "statue" )
  return notify_fail("你完全尋找不出任何異狀!!!\n");
  else
  message_vision("經過你明察暗訪，發現每個雕像都有武器形的凹洞。\n",ob);
  return 1;
}

int do_enter(string str)
{
 mapping weapons = ([
  "sun_fire_sword in sworder" : 1,
  "liyu_pen in scholar" : 2,
  "bird-blade in blader" :3,
 ]);
 object ob=this_player(),obj=this_object();
 string stones,name,str1;
 if(ob->query("highsworder")==1||ob->query("bloodsword")==2)
  return notify_fail("你已開過封印了！！\n");
 if((weapons[str]==1)&& (ob->query("class")=="swordsman"))
  {
  ob->set_temp("qsword",1);
    if( done== 0 )
      {
      message_vision(HIW + "你把靈器推入雕像，頓時雕像嘎嘎作響！\n" + NOR,ob);
      message_vision(HIW + "頓時，由凹洞處產生一個漩渦形的氣漩,一個不小心$N已被極大的吸力將吸入【空洞】內。\n\n\n" + NOR,ob);
      ob->move("/open/gsword/second/room/sword/s1.c");
      message_vision(HIW + "$N被吸入後，氣漩馬上消失無蹤!!\n" + NOR,ob);
      obj->set_temp("pass/swordsman",ob->query("id"));
      done = 1;
      }
   else{
    message_vision("雕像毫無反應...\n",ob);
    message_vision(HIY + "$N看了看地上的腳印，發覺似乎有人來過。\n" + NOR,ob);}
  return 1;
  }
 if((weapons[str]==2) && (ob->query("class")=="scholar"))
 {
  ob->set_temp("qsword",1);
   if( done1== 0 )
      {
       message_vision(HIW + "你把靈器推入雕像，頓時雕像嘎嘎作響！\n" + NOR,ob);
       message_vision(HIW + "頓時，由凹洞處產生一個漩渦形的氣漩,一個不小心$N已被極大的吸力將吸入【空洞】內。\n\n\n" + NOR,ob);
       ob->move("/open/gsword/second/room/scholar/sch1.c");
       message_vision(HIW + "$N被吸入後，氣漩馬上消失無蹤!!\n" + NOR,ob);
       obj->set_temp("pass/scholar",ob->query("id"));
       done1=1;
      }
    else{
    message_vision("雕像毫無反應...\n",ob);
    message_vision(HIY + "$N看了看地上的腳印，發覺似乎有人來過。\n" + NOR,ob);}
  return 1;
  }
 if((weapons[str]==3) && (ob->query("class")=="blademan"))
  {
  ob->set_temp("qsword",1);
  if( done2== 0 )
      {
       message_vision(HIW + "你把靈器推入雕像，頓時雕像嘎嘎作響！\n" + NOR,ob);
       message_vision(HIW + "頓時，由凹洞處產生一個漩渦形的氣漩,一個不小心$N已被極大的吸力將吸入【空洞】內。\n\n\n" + NOR,ob);
       ob->move("/open/gsword/second/room/blade/b1.c");
       message_vision(HIW + "$N被吸入後，氣漩馬上消失無蹤!!\n" + NOR,ob);
       obj->set_temp("pass/blademan",ob->query("id"));
       done2=1;
      }
     else{
    message_vision("雕像毫無反應...\n",ob);
    message_vision(HIY + "$N看了看地上的腳印，發覺似乎有人來過。\n" + NOR,ob);}
  return 1;
  }
 else
 {
  message_vision(HIR + "誤觸機關！..遭封印反噬！\n" + NOR,ob);
  ob->unconcious();
 }
return 1;
}
