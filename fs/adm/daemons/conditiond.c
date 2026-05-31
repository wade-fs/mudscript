//conditiond.c CON_D 顯示狀態 by ACKY
//更新日期 2011/10/9 by blazakira

#include <ansi.h>

string con_query( object ob )
{
  string condition;
  condition = "";

// 武學
  if( ob->query_temp("losehurt") )
  {
    if(ob->query("family/family_name") == "金刀門") {condition += HIG"『刃葉刀鎧』";}
    else{condition += HIR"『血氣鬥鎧』";}
  }
  if( ob->query_condition("giftout") )
    condition += HIG"『筋骨異常』";
  if( ob->query_condition("mkpowerup") )
  {
    if(ob->query("family/family_name") == "金刀門") {condition += HIG"『殺意無限』";}
    else{condition += HIW"『嗜血狂暴』";}
  }
  if( ob->query_temp("addenforce") )
  {
    if(ob->query("family/family_name") == "金刀門") {condition += HIG"『落葉刀勁』";}
    else{condition += HIR"『血勁』";}
  }
  if( ob->query_condition("powerup") )
    condition += HIC"(凌霜奇勁)";
  if( ob->query_condition("kang-power") )
    condition += HIR"(烈焰浩氣)";
  if( ob->query_condition("god_out") )
    condition += HIM"(仙雲護體)";
  if(ob->query_temp("gold-fire"))
    condition += YEL"("HIR"極火"HIY"金身"YEL")";
  if(ob->query_temp("ashura_fight"))
    condition += HIW"("HIM"修羅鬥氣"HIW")";
  if( ob->query_condition("crazy") )
    condition += HIM"("HIR"狂暴"HIB"魔化"HIM")";
  if( ob->query_temp("basicup"))
    condition += MAG"(舒筋活骨)";
  if( ob->query_temp("beg_ok"))
    condition += HIM"(捻花指力)";
  if( ob->query_temp("hpup"))
    condition += CYN"(伐毛洗髓)";
  if( ob->query_temp("mightup"))
    condition += HIG"(血脈賁張)";
  if( ob->query_temp("crazy_dragon/on") )
    condition += RED"("HIR"浩日狂龍"RED")";
  if( ob->query_temp("needle_up") )
    condition += YEL"("HIY"秘針龍騰"YEL")";
  if( ob->query_temp("def_cold") )
    condition += CYN"("HIC"防護冰雪"CYN")";
  if( ob->query_temp("def_fire") )
    condition += RED"("HIR"防護火焰"RED")";
  if( ob->query_temp("mpower") )
    condition += YEL"("HIY"玄元奇勁"YEL")";

// 受傷, 中毒

  if( ob->query_condition("dark_poison")) 
    condition += HIB"(深宮奇毒)";
  if( ob->query_condition("fire_poison"))
    condition += HIR"(火雲邪毒)";
  if( ob->query_condition("five_poison"))
    condition += RED"(五毒神掌)";
  if( ob->query_condition("flower_poison"))
    condition += NOR"("HIM"花"HIG"柳"HIR"病"NOR")";
  if( ob->query_condition("snake_poison"))
    condition += RED"(蛇毒)";
  if( ob->query_condition("rose_poison"))
    condition += HIM"(玫瑰花毒)";
  if( ob->query_condition("spring"))
    condition += HIR"(慾火焚身)";
  if( ob->query_condition("super_snake_poison"))
    condition += HIM"(猛蛇毒)";
  if( ob->query_condition("evil_poison") || ob->query_condition("evil_pill01")|| ob->query_condition("evil_pill02"))
    condition += RED"(噬魂蠱毒)";
  if( ob->query_condition("no_power_e") )
    condition += HIY"(內勁失控)";
  if( ob->query_condition("no_power_f") )
    condition += HIW"(氣流纏身)";
  if( ob->query_condition("no_power") )
    condition += HIR"(劍光盲目)";
  if( ob->query_condition("flower") )
    condition += HIM"(昏軟無力)";
  if( ob->query_condition("lyssa") )
    condition += HIR"(狂犬病)";
  if( ob->query_condition("mogi") )
    condition += HIM"(入滅)";
  if( ob->query_condition("ff_poison") )
    condition += HIY"(氣血失調)";
  if( ob->query_condition("blockade") )
    condition += HIW"(穴道被封)";
  if( ob->query_condition("skyfire") )
    condition += NOR"("HIR"天"HIY"火"HIR"灼"HIY"身"NOR")";
  if( ob->query_condition("tsunami") )
    condition += NOR"("HIB"內"HIY"息"HIB"翻"HIC"騰"NOR")";
  if( ob->query_condition("burn") )
    condition += HIR"(灼傷)";
  if( ob->query_condition("mess") )
    condition += HIM"(混亂)";
  if( ob->query_condition("power-down") )
    condition += HIB"(虛弱)";
  if( ob->query_condition("keeup") )
    condition += HIW"(化勁成氣)";
  if( ob->query_temp("keeup") )
    condition += HIW"(化勁成氣)";

  if( ob->query_condition("hellfire") )
    condition += HIR"(地獄之火)";
  if( ob->query_condition("ice") )
    condition += HIW"(冰風襲擊)";
  if( ob->query_condition("hellthunder") )
    condition += HIC"(九天真雷)";
  if(ob->query_condition("misforce"))
    condition += HIM"(走火入魔)";
  if(ob->query_condition("thunder"))
    condition += HIC"(雷電之氣)";
  if( ob->query_condition("blade") )
    condition += HIY"(刀傷)";
  if( ob->query_condition("ad-blade") )
    condition += BLU"(無極刀傷)";
  if( ob->query_condition("cold") )
    condition += HIW"(凍傷)";
  if( ob->query_condition("u-stial") )
    condition += HIG"(毒傷)";
  if( ob->query_condition("star-stial") || ob->query_condition("hart") )
    condition += HIY"(內傷)";
  if( ob->query_condition("bleeding") )
    condition += HIR"(流血)";
  if( ob->query_condition("ghost") )
    condition += NOR+BLU"(陰魂不散)";
  if( ob->query_condition("dog") )
    condition += NOR+HIC"(狗蝨毒)";
  if( ob->query_temp("block_sweat") )
    condition += HIW"〈蒙汗藥〉";
  if( ob->query_condition("fog-poison") || ob->query_condition("fog_poison") )
    condition += HIG"(毒蛙之毒)";
  if( ob->query_condition("death") )
    condition += HIB"(死靈魔音)";
  if( ob->query_temp("over/r-eyes")==1 && ob->query_temp("over/l-eyes")==1 )
    condition += RED"(雙目失明)";
  else if( ob->query_temp("over/r-eyes")==1 || ob->query_temp("over/l-eyes")==1 )
    condition += HIR"(獨眼禦敵)";
  if( ob->query_temp("over/right")==1 && ob->query_temp("over/left")==1)
    condition += HIW"(雙手乏力)";
  else if( ob->query_temp("over/right")==1 || ob->query_temp("over/left")==1)
    condition += WHT"(單手禦敵)";

// 其他
  if( ob->query_condition("force") )
    condition += HIW"(練氣)";
  if( ob->query_condition("dhyana") )
    condition += HIC"(參禪)";
  if( ob->query_condition("nectar") )
    condition += HIY"(千年精血)";
  if( ob->query_condition("young") )
    condition += HIG"(青春)";

  if( ob->query_condition("drunk") )
    condition += HIG"(酒醉)";
  if( ob->query_temp("ref_shield") )
    condition += HIC"〈玄冰護體〉";
  if( ob->query_temp("absorb") )
    condition += HIM"〈水月神鏡〉";
  if( ob->query_temp("mana_shield") )
    condition += HIW"〈幻夢之翼〉";
  if( ob->query_temp("mana_shield2") )
    condition += HIY"〈幻夢之翼〉";
  if( ob->query_temp("mana_shield3") )
    condition += HIY"〈幻夢之翼〉";
  if( ob->query_temp("mana_shield4") )
    condition += HIY"〈幻夢之翼〉";
  if(ob->query_temp("no_roar"))
    condition += YEL "(蠍毒)";
  if(ob->query_temp("hardshell"))
    condition += HIG"(硬甲)";
  if( ob->query_temp("superforce")==1 )
    condition += HIW"〈白雲煙〉";
  if( ob->query_temp("superforce")==2 )
    condition += HIM"〈玫蕩霞〉";
  if( ob->query_temp("superforce")==3 )
    condition += YEL"〈土崑崙〉";
  if( ob->query_temp("superforce")==4 )
    condition += HIC"〈碧雪冰〉";
  if( ob->query_temp("superforce")==5 )
    condition += MAG"〈紫星河〉";
  if( ob->query_temp("superforce")==6 )
    condition += WHT"〈玄渾沌〉";
  if( ob->query_temp("superforce")==7 )
    condition += HIB"〈靛滄海〉";
  if( ob->query_temp("superforce")==8 )
    condition += HIY"〈金晨曦〉";
  if( ob->query_temp("superforce")==9 )
    condition += HIR"〈血穹蒼〉";
  if( ob->query_temp("superforce")==10 )
    condition += HIG"〈玄宇宙〉";
  if(ob->query_temp("spirit_curse"))
    condition += YEL"("HIR"惡"HIB"靈"HIR"纏"HIB"身"YEL")";
  if( ob->query_condition("wn_move") )
    condition += HIB"("HIR"暗殺中"HIB")";
  if( ob->query_temp("invis"))
    condition += CYN"("HIC"隱匿中"CYN")";
  if( wizardp(ob) && (ob->query("env/invis") || ob->query("env/隱身")) )
    condition += HIK"(隱身中)";
  if(ob->query("ghost"))
    condition += BLU"(鬼氣)";
  if( condition )
    return condition + NOR;
  return "";
}
