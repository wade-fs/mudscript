//set("sec_kee","dhyana"); //設靈氣為佛法
//測試完畢 需增設職業限制

inherit ITEM;
inherit F_CLEAN_UP;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>

object me;

void create()
{
  set_name(HIY + "佛珠" + NOR,({"prayer beads","beads","b"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","這是幫助打坐靜心的法器。");
    set("unit","串");
    set("no_auc",1); //已設定變色 因此道具不離身 以免需多設判斷
    set("no_put",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_drop",1);
    set("no_steal",1);
  }
  setup();
}

int query_autoload()
{
  return 1;
}

void init() 
{
  object ob;
  me = environment();
  ob=present("prayer beads",me);
  if(ob&&ob->name()==HIY + "佛珠" + NOR)
  {
    add_action("do_pray","pray");
    add_action("do_abandon","destruct");
  }
}

int do_pray(string arg)
{
  object ob = this_object();

  int force,magic,spells;
  string ena_magic,ena_spells;
  seteuid(getuid());
  force = me->query_skill("force", 1); //當下force做基礎
  magic = me->query_skill("magic", 1) /2; 
  spells = me->query_skill("spells", 1) /2; 

  if( !arg ) //arg不指定 >> 跳出
    return 0;
  arg=lower_case(arg);
  if( !ob = present(arg,me) ) //身上沒有佛珠 >> 跳出
    return 0;
  if( ob != this_object() )
    return 0;
  if( me->query("sec_kee") != "dhyana" ) //如果已經有其他種靈氣則不許打坐
    return notify_fail("你確定要參悟佛法嗎？那會使你放棄使用其他靈氣的可能性喔！放棄靈氣需輸入(destruct seckee)。\n同時會使靈氣重新修煉。\n");
  if (me->query_condition("force")) //如果已經在蹲內力就不能打坐
    return notify_fail (MAG + "你正在忙著驅使體內的內息做周天循環，顧不得打坐參禪呢。\n" + NOR);
  if(me->query_condition("dhyana") > 0)
    return notify_fail("你已經藉著"+ob->name(1)+"開始打坐參禪了。\n");
  if(me->is_fighting()) notify_fail("戰鬥中怎能打坐入定呢，好好的與對手交流吧。\n");
  if(me->query_condition("ff_poison"))
    return notify_fail("你氣血失調，無法運氣。\n");
  if(me->query_temp("saving_die"))
    return notify_fail("你正在救人，沒有辦法運氣!!\n");
  if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
    return notify_fail("你現在精神狀況太差了，無法凝神專一！\n");
  if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
    return notify_fail("你現在精力不夠，無法控制內息的流動！\n");
  if(me->is_busy()) notify_fail("你正在忙碌中！\n");
  if(force < (magic+spells)*2) return notify_fail("您的基本內力功\力不足，無法練氣。\n"); //至少force > (magic+spells原值)的限制
  if (me->query_condition("no_power_e"))
    return notify_fail (HIM + "你感覺到體內有無數的氣勁亂流，使你無法正常的使用內力。\n" + NOR);
  if (me->query_temp("crazy"))
    return notify_fail (HIR + "你正陷入狂暴狀態，無法控制內息流動。\n" + NOR);
  if (me->query_condition("misforce"))
    return notify_fail (HIC + "你走火入魔，內力大減，無法動彈，氣息大亂。\n" + NOR);
  if (me->query_condition("star-stial"))
    return notify_fail (HIB + "你的所受的內傷發作，只覺得胸口出現一陣陣絞痛。\n" + NOR);
  if ((me->query("food")<1 || me->query("water")<1) && userp(me)) {
    if (random(100) < 1) {
      me->receive_wound ("kee", me->query("age"));
      return notify_fail( RED + "你感覺又餓又渴，一時之間無法控制真氣，受到了內傷！" + NOR );
    }
    return notify_fail( BLU + "你感覺又餓又渴！無法運氣！\n" + NOR );
  }
/*//佛法測試中 所以暫時關閉
  ena_magic = me->query_skill_mapped("magic");
  if( !stringp(ena_magic) )
    return notify_fail("你必須先用 enable 選擇你要用的法術心法。\n"); //也許根據使用的是大乘佛法 或是小乘佛法做訊息改變
  ena_spells = me->query_skill_mapped("spells");
  if( !stringp(ena_spells) )
    return notify_fail("你必須先用 enable 選擇你要用的咒術心法。\n");
*/
  me->apply_condition("dhyana",(magic+spells));
  message_vision(HIW + "$N原地靜心打坐後，手握$n"+HIW+"開始掐捻念佛.....$n"+HIW+"發出沉穩的光芒。\n" + NOR,me,ob);
  ob->set("name",HIM + "( 拈花 )" + NOR+HIY + "佛珠" + NOR);
  return 1;
}

int do_abandon( string arg )
{
  if( me->query("sec_kee") == "dhyana" )
    return notify_fail("你已經學會至上佛法，無法拋棄之。\n");
  if( !arg || arg != "seckee" ) return 0;
  me->delete("sec_kee"); //刪除靈氣種類
  me->delete("max_s_kee"); //刪除最大靈氣值>>即score顯示資料下不顯示靈氣一項
  return notify_fail("你放棄了你身上的靈氣。\n");
}

//停止打坐需改回原色
void change_color()
{
  this_object()->set("name",HIY + "佛珠" + NOR);
}
