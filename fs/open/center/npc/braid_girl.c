//sale_girl.c
//作為recall區域清除生活物資的npc 搭配入口房間禁止離開(/open/trans/room/room4) by blazakira 2010/10/25
//將sac的判斷更加嚴謹 by blazakira 2010/12/15
#include <obj.h>
#include <ansi.h>
#include "/open/open.h"

inherit F_VENDOR;
void create()
{
  set_name("辮子女孩", ({ "braid girl", "girl" }) );
  set("gender", "女性" );
  set("age", 15);
  set("per", random(7)+28);
  set("kar", random(7)+28);
  set("nickname",RED + "櫻桃小辣椒" + NOR);
  set("long", @LONG
她姊姊就是「小辣椒」賣火柴的小辣妹，姊妹兩人都為了讓fs更好而努力著。
LONG);
  set("attitude", "friendly");
  set("rank_info/respect", "少女");
  set("combat_exp",180);
  set("chat_chance",5);
  set("chat_msg",({
  (: random_move :), //多一個走動的可能 主要是依據心跳中的走動功能
  "辮子女孩面容憔悴的道﹕謝謝好心的大爺小姐們的幫助。\n",
  "辮子女孩帶點微笑的道﹕新人需要食物的話，可到何若蘋姊姊那裡，她會很熱心地給予幫助。\n",
  "辮子女孩俏皮的道﹕經驗超過三十五萬的大俠可不是新人了喔。\n", //此時玩家可打到exp100萬的npc
  "辮子女孩小小聲的說﹕武學之道猶如逆水行舟，是以我姊姊可提供新人大俠們一點意外的保障。\n",
  "辮子女孩眨眨眼道﹕有一定的經驗但是未滿一百萬的大俠才有資格跟我姊姊做更深的交談喔。\n",
  }));
  set_temp("mark/leave_ng", 1 ); //避免本npc離開本區域(recall)而設立的mark
  setup();
}

void init()
{
  set_heart_beat(1);
}

void heart_beat()
{
//參考郭襄與趙高的逃跑模式 //以下得在使用前先定義
  object *inv,ob,env;
  mapping exit; 
  string *exit_name;
  int i;
  ob=this_object();

//每次心跳就撿拾一次並刪除因玩家離線所掉落的道具 by blazakira
//基本上是針對純喫茶 小拉大龍棕 喚雲扇等 生活物資
  if(!environment()) return ;
  if(!ob) return ;
  env = environment(ob);
  if( ob->query("kee") <= 0 )
  {
    set_heart_beat(0);
    ob->die();
  }
  else {
    inv=all_inventory(environment(ob));
    for(i=0;i<sizeof(inv);i++){
      if(!inv[i]) continue;
      if(inv[i]->query("id") ==ob->query("id") || living(inv[i])) continue; //當然不能是自己
      if(inv[i]->query("no_sac")) continue;
      if(!inv[i]->query("食物") && !inv[i]->query("液體") && inv[i]->query("id") != "cloud fan") continue; //需注意該房間是否固定場景的物件
      message_vision(HIC + "$N以很遺憾的心情將"+inv[i]->query("name")+HIC"("+inv[i]->query("id")+HIC")歸入塵土風逝。\n" + NOR,ob);
      destruct(inv[i]);
    }
  }
  exit = env->query("exits"); //因為會有偶發的出口被刪除的可能性 這是系統預設的清除記憶體的作法 因此提前做參數設定並額外補上判斷
  if( env && exit && (random(100) < 65) )
  {
    exit_name = keys(exit);
    i = random(sizeof(exit_name));
    command(exit_name[i]);
  }
  ::heart_beat();
}
