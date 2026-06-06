/*
太多了啊 列舉一下吧
先秦：《神農本草經》神農氏   《皇帝內經》
漢代：馬王堆漢墓醫書    《黃帝內經素問》 、張仲景《傷寒雜病論》、張仲景《金匱要略》
唐代：孫思邈，《千金方》，明代：王叔和的《脈經》、皇甫謐《針灸甲乙經》、陶弘景《本草經集注》、葛洪《肘後備急方》、巢元方《諸病源候論》、蘇敬《新修本草》 、王燾《外台秘要》、元丹貢布《四部醫典》、《太平聖惠方》、王惟一《銅人腧穴針灸圖經》 北宋：宋慈《洗冤集錄》
回回藥方    忽思慧《飲膳正要》、許國禎《御藥院方》 、劉完素《素問玄機原病式》、張子和《儒門事親》、朱丹溪《格致余論》、李東垣《脾胃論》、李時珍與《本草綱目》、劉文泰《本草品彙精要》、吳又可《溫疫論》、徐春甫《古今醫統大全》、葉天士《臨證指南醫案》、吳鞠通《溫病條辨》、王孟英《溫熱經緯》、薛生白《濕熱條辨》、王清任《醫林改錯》、《古今圖書集成醫部全錄》、《聖濟總錄》  
近代醫學名著  《古今圖書集成》 可能還有很多吧 就知道這些了～～
*/

#include <ansi.h>
#include <combat.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
  seteuid(geteuid());
  set_name(YEL"銅人腧穴針灸圖經"NOR, ({ "acupuncture picture book", "book", "picture book", "acupuncture" }) );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "本");
    set("no_get",1);
    set("no_auc",1);
    set("no_put",1);
    set("no_sell",1);
    set("no_save",1);
    set("no_give",1);
    set("no_drop",1);
//    set("no_sac",1);
//    set("no_steal",1);
  }
  setup();
}

string long()
{
  return @TEXT
    一本看起來很舊且不起眼的書，但是似乎有神力附著在上頭，導致水火不侵。相傳記載
著銀針門起源醫術的有關記載與醫術本源。

TEXT;
}

void init()
{
  object me;
  me = environment();
  if( !this_object()->query("ower") )
  {
    this_object()->set("ower",me->query("id"));
  }

  if(!me) return ;
  me->set_temp("needleup",2); //持有即給予技能使用許可的專屬獎勵mark
}

int query_autoload ()
{
  object me;
  me = environment();

  if(me->query("class")=="doctor" || wizardp(me))
  {
    return 1;
  }
  return 0;
}
