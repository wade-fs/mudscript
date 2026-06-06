//atman_pill.c
//固本培元 拆成兩個 前者為增加技能經驗 後者暫定提昇等級
//設定直接呼叫則為基礎無效果
//獎勵應為隨機 使得玩家有機率得到並非想要的basic exp pill 以便增加趣味性

inherit ITEM;
//inherit COMBINED_ITEM;
#include <ansi.h>
int i;
string kind_p;

void create()
{
  set_name(HIG + "固本丹" + NOR, ({"base pill","pill"}) );
  set("long","別看這顆丹丸不起眼，這可是少林寺聞名天下可增進功\力的秘傳丹藥喔！不過" + HBCYN+HIY + "無法指定" + NOR + "增加\n"+
    "的" + HBCYN+HIW + "種類" + NOR + "可就令人感到無奈了。\n"); //tsk 這樣還看不出來獎勵採隨機制 我也沒辦法了（苦笑 by blazakira
  set("unit", "盒");
  set("base_unit", "粒");
  set("no_auc",1);
  set("no_sell",1);
  set("no_give",1);
  set("no_sec",1);
  set("no_put",1);
  set("no_drop",1);
  set("no_steal",1);
  set("no_save",1);
  set("no_get",1);
  set("value",10000000);
//  set_amount(1);
  setup();
}

void init()
{
  kind_p=this_object()->query("種類");
  i=random(10)+1; //範圍限制為1~10之間
  set("query_i",i); //作為備份紀錄 並無他用
  if ( kind_p && !query("query_種類") ) {
//    add("name", "--"+kind_p+"效");
    set("query_種類",kind_p); //作為備份紀錄 並無他用
  }
  if ( this_player()==environment() )
  {
    add_action("eat_pill", "eat");
  }
}

int eat_pill(string arg)
{      
  object ob,me=this_player();
  int max_mana,mana;
  int magic = me->query_skill("magic");
  int spells = me->query_skill("spells");
  int force = me->query_skill("force");

  if( !arg )                      return 0;
  arg=lower_case(arg);
  if( !ob = present(arg,me) )     return 0;
  if( ob != this_object() )       return 0;

//在init()設定改變丹藥名稱的方式來指定種類
  switch (kind_p)
  {
    case "magic" : //法術
      me->improve_skill( "magic", i);
      me->add("mana",-magic*10);
      break;
    case "spells" : //咒術
      me->improve_skill( "spells", i);
      me->add("atman",-spells*10);
      break;
    case "sword" : //基本劍術
    case "blade" : //基本刀法
    case "stabber" : //基本刺術
    case "staff" : //基本杖法
    case "throwing" : //暗器使用
    case "unarmed" : //撲擊格鬥技巧
    case "whip" : //基本鞭法
    case "dagger" : //短兵刃
    case "parry" : //拆招卸力之術
    case "dodge" : //跳躍閃躲之術
    case "move" : //基本輕功
    case "force" : //基本內功 此項純屬惡搞 giggle
      me->improve_skill( kind_p, i);
      me->add("force",-force*10);
      break;
    default :
      me->add("quests/bonze/water/pill/problem",1); //紀錄非正常途徑的mark
      tell_object(me,BLINK+HIC + "哎呀！糟糕，你吃到" + HIG + "固本丹" + HIC + "的偽藥了！\n頓時你覺得氣血失調。\n" + NOR); //非正當途徑取得時 則無效果
      me->apply_condition("ff_poison",10);
//      add_amount(-1);
      destruct(ob);
      return 1;
      break;
  }
  me->add("quests/bonze/water/pill/"+kind_p,1); //紀錄吃過哪種pill
  tell_object(me,HIW + "你吃下之後感到一股熱流在經脈裡流轉！\n" + NOR);
  tell_object(me,"(你發現到你的基礎技能"+HIY+kind_p+NOR+"增加熟練度"+HIY+i+NOR+"點)\n" + NOR);
//  add_amount(-1);
  destruct(ob);
  return 1;
}
