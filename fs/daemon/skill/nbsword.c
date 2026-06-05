// 仙劍二轉sk ..(限"仙劍"且不能當官)by appo
// 為魔劍招式..版權所有...翻用前請先通知
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void at_head(object me, object victim, object  weapon, int damage);
void at_hand(object me, object victim, object  weapon, int damage);
void at_foot(object me, object victim, object  weapon, int damage);
void at_miss(object me, object victim, object  weapon, int damage);
void at_wind_1(object me, object victim, object  weapon, int damage);
void at_wind_2(object me, object victim, object  weapon, int damage);
void at_wind_3(object me, object victim, object  weapon, int damage);
void at_wind(object me, object victim, object  weapon, int damage);
void at_quick(object me, object victim, object  weapon, int damage);
void new_1(object me, object victim, object  weapon, int damage);
void new_2(object me, object victim, object  weapon, int damage);
void new_3(object me, object victim, object  weapon, int damage);
int kar,cps,str,cor,int1,spi;
int sp_value;
string *ghost = ({
HIY+HBBLU + "魔劍連擊      第一劍  ﹣﹦≡ " + HIC + "幻魔" + HIM + "血殺" + HIY + " ≡ ﹦﹣" + NOR,
HIB+HBMAG + "魔劍連擊      第二劍  ﹣﹦≡ " + HIC + "魔魂" + HIM + "噬血" + HIB + " ≡ ﹦﹣" + NOR,
HIR+HBBLU + "魔劍連擊      第三劍  ﹣﹦≡ " + HIC + "魔殺" + HIM + "無極" + HIR + " ≡ ﹦﹣" + NOR,
HIG+HBRED + "魔劍連擊      第四劍  ﹣﹦≡ " + HIC + "魔魂" + HIM + "長嘯 " + HIG + "≡ ﹦﹣" + NOR,
HIR+HBYEL + "魔劍連擊      第五劍  ﹣﹦≡ " + HIC + "魔寒" + HIM + "極冰 " + HIR + "≡ ﹦﹣" + NOR,
HIM+HBCYN + "魔劍連擊      第六劍  ﹣﹦≡ " + HIC + "魔嘯" + HIR + "九天 " + HIM + "≡ ﹦﹣" + NOR,
HIC+HBMAG + "魔劍連擊      第七劍  ﹣﹦≡ " + HIB + "萬魔" + HIM + "歸宗 " + HIB + "≡ ﹦﹣" + NOR,
HIM+HBBLU + "魔劍連擊      第八劍  ﹣﹦≡ " + HIR + "天魔" + HIG + "怒吼 " + HIM + "≡ ﹦﹣" + NOR,
YEL+HBRED + "魔劍連擊      第九劍  ﹣﹦≡ " + HIM + "天降" + HIG + "魔威 " + YEL + "≡ ﹦﹣" + NOR,
});
mapping *action = ({
//01
             ([ "action":"$N雙手微抬，腳步緩緩移動，不斷積蓄內勁，只見$N雙眼放射出慘綠的光茫，突地平地一聲響，$N大喝一聲" + HIR + "【血氣方剛】" + NOR+"$n只覺腦中一震，全身呆滯，而$N稱此機會, 手中長劍幻化出無數劍影, 向$n的全身罩下．",
                "dodge"      :               -105,
                "parry"      :                -100,
                "damage"     :                300,
                "force"      :                300,
                "damage_type":               "瘀傷"
        ]),
//02
             ([  "action":"$N將手中長劍暗藏於後，側身橫移數步，地下深印出數個腳印，口中唸唸有詞，隨著長劍的揮舞，數道劍氣由劍中射出，正是" + HIR + "『血魔』" + NOR+"殺招之一" + HIM + "【血肉橫飛】" + NOR+"霎時滿天劍氣縱橫在$n身上劃去．",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                330,
                "force"      :                330,
                "damage_type":               "割傷"
        ]),
//03
             ([  "action" :"$N臉部青絲暴露，濃烈的殺氣從$N的雙眼透出，只見$N不停揮舞佩劍，勁氣中夾帶著令人聞之喪膽的殺氣，正是" + HIW + "『血魔』" + NOR+"絕學之一" + CYN + "【血染江湖】" + NOR+"天空倏然一片血紅，$n也受到血氣包圍．",
                "dodge"      :                -110,
                "parry"      :                -120,
                "damage"     :                360,
                "force"      :               350,
                "post_action":               (: at_head :),
                "damage_type":               "刺傷"
        ]),
//04
             ([  "action" : "$N將" + HIR + "血魔劍招" + NOR+"發揮到極限，瞻之在前，忽焉在後，如鬼魅般穿梭在$n四周，只見$N身形一弓，長劍，一道半月形的勁氣猛然像$n湧去，",
                "dodge"      :               -120,
                "parry"      :                -120,
                "damage"     :                380,
                "force"      :               350,
               "post_action":               (: at_hand :),
                "damage_type":               "劈傷",
        ]),
//05
             ([  "action" : "$N屈體弓身，將長劍插入地中，全身籠罩在一片藍光中，地面宛如波濤般浮動，隨著蓄積的內勁，藍光不斷增加，倏然藍光一瞬，一道駭人藍箭以由地底向$n疾射而去",
               "dodge"       :               -130,
                "parry"      :                -140,
                "damage"     :               390,
                "force"      :                380,
              "post_action":               (: at_foot :),
                "damage_type":               "刺傷",
        ]),
//06
             ([  "action" :HIB + "$N使出一招" + HIM + "魔 光 " + HIC + "耀 九 天" + HIB + "" + HIR + "，手中魔劍散發出無比的光茫，忽然間魔劍脫手而出升至九天吸收日月精華\n" + HBBLU + "幻化成萬道光茫從$n四面八方急射而至，令$n根本無從招架。" + NOR,
                 "dodge"      :                -150,
                 "parry"      :                -160,
                 "damage"     :                 380,
                 "force"      :                 500,
                 "post_action":                (: new_3 :),
                 "damage_type":               "劍傷"
        ]),
//07
             ([  "action" :HBBLU + "$N大喝一聲，狂嘯動地，滅絕八方，凌厲劍勢急旋怒颳，不斷層疊遞增蓄勢待發" + NOR + "
              "+HIR + "＿ˍ▁▂▃▄▅▆▇█ " + HIC + "血殺" + HIY + "無極 " + HIW + "… " + HIM + "熾血" + HIC + "凌空 " + HIR + "█▇▆▅▄▃▂▁ˍ＿\n" + HIW + "大地彷彿被此招所牽引呈現一遍赤紅血色，$n亦被此招所嚇面如土色，動彈不得．" + NOR,

                 "dodge"      :                -160,
                 "parry"      :                -160,
                 "damage"     :                 410,
                 "force"      :                 380,
                 "post_action":                (: new_1 :),
                 "damage_type":               "劍傷"
        ]),
//08
             ([  "action" :HIY + "$N眼中忽露兇光" + HIW+HBBLU + "ζ " + HIR + "魔  " + HIG + "～  " + HIC + "道  " + HIG + "～  " + HIG + "無  " + HIG + "～  " + HIM + "極 " + HIW + "ζ" + NOR + "\n" + HIY + "此招正是魔字訣無上之招，只見無數劍氣盤旋$n四周，瞬息間$n全身血流不止。" + NOR,

                 "dodge"      :                -150,
                 "parry"      :                -170,
                 "damage"     :                 380,
                 "force"      :                 400,
                 "post_action":                (: new_2 :),
                 "damage_type":               "劍傷"
        ]),
//09 血魔殺-1 (為增加出招率, 因此用三招表示, 每招各三殺, random 出一招)
             ([ "action"     :HIW + "$N感受四面八方的魔氣，無窮無盡的勁力由四周湧入$N體內，只見$N手中長劍吸食萬魔魔氣，奮而使出使出血魔霸劍奧義狂殺技" + NOR + "
                           "+HBRED + "～血 魔 殺 法～ " + NOR,
                 "dodge"     :              -170,
                 "parry"     :              -160,
                 "damage"    :               430,
                 "force"     :               300,
                 "post_action":              (: at_wind_1 :),
                 "damage_type":               "割傷",
        ]),
//10 血魔殺-2
             ([ "action"     :HIW + "$N感受四面八方的魔氣，無窮無盡的勁力由四周湧入$N體內，只見$N手中長劍吸食萬魔魔氣，奮而使出使出血魔霸劍奧義狂殺技" + NOR + "
                           "+HBRED + "～血 魔 殺 法～ " + NOR,
                "dodge"      :                -180,
                "parry"      :                -180,
                "damage"     :                 450,
                "force"      :                 500,
                "post_action":               (: at_wind_2 :),
                "damage_type":               "割傷",
        ]),
//11 血魔殺-3
             ([ "action"     :HIW + "$N感受四面八方的魔氣，無窮無盡的勁力由四周湧入$N體內，只見$N手中長劍吸食萬魔魔氣，奮而使出使出血魔霸劍奧義狂殺技" + NOR + "
                           "+HBRED + "～血 魔 殺 法～ " + NOR,
                "dodge"      :                -180,
                "parry"      :                -180,
                "damage"     :                 450,
                "force"      :                 500,
                "post_action":               (: at_wind_3 :),
                "damage_type":               "割傷",
        ]),

//12 血魔殺 最終技, 威力強
             ([ "action"     :HIW + "$N感受四面八方的魔氣，無窮無盡的勁力由四周湧入$N體內，只見$N手中長劍吸食萬魔魔氣，奮而使出使出血魔霸劍狂殺技" + HIC + "暴血魔極殺" + NOR,
                "dodge"      :                -180,
                "parry"      :                -180,
                "damage"     :                 450,
                "force"      :                 500,
                "post_action":               (: at_wind :),
                "damage_type":               "割傷",
        ]),
//13 blood_sword 瘋狂連擊技-血霧刃 如ppl 當官或拜過ppl 則無此招-
              ([ "action"     :HIW + "$N殺的性起，頓時將血魔霸劍精華完全融會貫通，頓時間，$N全身覆蓋\在無比亮紅的血光中，瘋狂殺意引爆無窮血光，奮而出血魔禁斷奧義\n"+HIM + "             ※※※※※    血霧刃    ※※※※※" + NOR + "
"+HIW + "隨著血光幻化成的血霧，$N消失於陣陣血霧中，只見血霧漸漸壟罩這整個空間！！！！" + NOR,
              "dodge"      :                 -190,
              "parry"      :                 -190,
              "damage"     :                 400,
              "force"      :                 500,
              "post_action":               (: at_quick :),
              "damage_type":               "劍傷",
             ]),
             });


int valid_learn(object me)
{


    if(me->query("bloodsword")!=2){
       tell_object(me,"你還不夠資格練血魔劍呢。\n");
        return 0;
}
       if( !me->query_temp("weapon")){
        tell_object(me,"練血魔劍必需先拿把劍。\n");
        return 0;
                                     }
       if( (me->query("potential") - me->query("learned_points")) < 25 ) {
        tell_object(me, "你的潛能不到二十五點，無法練此劍法。\n");
        return 0;
 }
        me->add("potential", -25);
  return   1;
}

mapping query_action(object me, object weapon)
{
       int skill_level, limit;
          kar=me->query_kar();
 cps=me->query_cps();
 str=me->query_str();
 cor=me->query_cor();
 int1=me->query_int();
 spi=me->query_spi();

        skill_level =(int)(me->query_skill("blood_sword",1));
        limit= (int)(skill_level/10);
        if (limit < 2 )
                return action[random(3)];
        if (limit < 3 )
                return action[random(4)];
        else if (limit < 4)
                      return action[random(5)+1];
        else if (limit < 5) 
                  return action[random(6)+2];
        else if (limit < 7) 
                  return action[random(7)+3];
        else if (limit < 9)
                 return action[random(7)+4];
        else if (skill_level==100 && me->query("swordskill/bloodz")==1)
        return action[random(7)+6];
        else
           return action[random(7)+5];

}
int valid_enable(string usage)
{
   return ( usage=="sword" || usage=="parry" );
   
}
void at_head(object me, object victim, object  weapon, int damage)
{
  sp_value =2*(str+cor)+cps+kar+spi;
   victim->receive_damage("kee",sp_value,me);
   COMBAT_D->report_status(victim);
}
void at_hand(object me, object victim, object  weapon, int damage)
{
  sp_value =2*(str+cor)+cps+kar+spi;
   victim->receive_damage("kee",sp_value,me);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
void at_foot(object me, object victim, object  weapon, int damage)
{
  sp_value =3*(str+cor)+cps+kar+int1;
   victim->receive_damage("kee",sp_value,me);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

//第一skill判斷式  (me->query("swordskill/sword1")==1)
void new_1(object me, object victim, object  weapon, int damage)
{
 int i;
 if (me->query("swordskill/sword1")==1)
 {
  message_vision(HIC + "$N翻身一躍而上九空之中，大喝一聲︰『" + HIR + "血霸四方" + HIC + "』\n" + NOR,me,victim);
  message_vision(sprintf(HIR + "$N身上血魔鬥氣隨之鼓動，配合血魔霸劍轉而使出" + HIC + "『" + HIR + "血霸四方神佛滅" + HIC + "』，身上霸氣無極，招式無窮無盡，當真神阻殺神，佛祖殺佛！！" + HIR + "\n" + NOR),me,victim);
   for(i=1;i<=4;i++)
   {
         switch(i)
     {
      case 1:
       message_vision(sprintf(HIR + "        ＿ˍ▁▂▃▄▅▆▇█" + HIM + "魔" + HIW + " " + HIB + "殺" + HIR + "█▇▆▅▄▃▂▁ˍ＿\n" + NOR),me,victim);
      break;
      case 2:
       message_vision(sprintf(HIR + "        ＿ˍ▁▂▃▄▅▆▇█" + HIG + "無" + HIW + " " + HIC + "極" + HIR + "█▇▆▅▄▃▂▁ˍ＿\n" + NOR),me,victim);
      break;
      case 3:
       message_vision(sprintf(HIR + "        ＿ˍ▁▂▃▄▅▆▇█" + HIG + "熾" + HIW + " " + HIC + "血" + HIR + "█▇▆▅▄▃▂▁ˍ＿\n" + NOR),me,victim);
      break;
      case 4:
       message_vision(sprintf(HIR + "        ＿ˍ▁▂▃▄▅▆▇█" + HIY + "凌" + HIW + " " + HIB + "空" + HIR + "█▇▆▅▄▃▂▁ˍ＿\n" + NOR),me,victim);
      break;
     }
     if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(sprintf(HIB + "強大魔殺挾帶無窮火勁如利刃般刺進$n體中，令$n痛不欲生！\n" + NOR),me,victim);
     victim->receive_wound("kee",180+random(50));
     victim->apply_condition("hellfire",random(3));
    }
    else
     {
        message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺著！\n" + NOR),me,victim);
     }
  }
 }
 else
 {
  message_vision(HIC + "\n" + HBBLU + "$N翻身一躍而上九空之中，大喝一聲︰『" + HIR + "血霸四方" + HIC + "』\n" + NOR,me,victim);

   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(sprintf(HIB + "強大魔殺如利刃般刺進$n體中，令$n痛不欲生！\n" + NOR),me,victim);
     victim->receive_wound("kee",100+random(50));
    }
    else
     {
        message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺著！\n" + NOR),me,victim);
     }

 }
}
// 第二skill 判斷式 (me->query("swordskill/sword2")==1)
//解迷難度及不易發現quest 強度稍高..
 void new_2(object me, object victim, object  weapon, int damage)
{
 int i;
if (me->query("swordskill/sword2")==1)
{
   message_vision(HBBLU + "$N運起渾身血魔鬥氣，發動全身五大魔劍劍魂，瞬間由身上竄出五道不同顏色的劍魂！\n" + NOR,me);
   message_vision(HIC + "瞬間五大魔劍劍魂，爆然而出，"+HIB + "藍糜"+HIR + "紅爓"+HIC + "青嵐"+HIG + "綠魅"+HIW + "白魂"+HIC + "五魂連星化成一招極殺之招『魂劍五魄』\n\n" + NOR,me);
  if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
   message_vision(HIC + "『魂劍五魄』挾帶無比$N無比魔意，竟喚醒身上無比血氣，五魄瞬間融合並幻化出魔獸熾血狂獅直奔$n而去！\n" + NOR,me,victim);
     message_vision(HIR + "
                                                       #####
                                               ###########
                                            ##########
                                        ###########
                                     ##########
                          ##       ##########
                         #       #########
                       ###    ############
                       ##    ###########
                     ###   ############
                     ###   ###########
                    ###################           ###
                   #################################
                  ##############################
                 #########################
                 #######################
         #      #################### \n" + NOR,me);
message_vision(HIR + "         ####  ##################
          ##############    ###
           ###########     ###
           ##########
          #########                        #####
          ########                ##########
           #######     ###   #########
           #### ##   ####  ######
           ### # #  ##########
           #####  #### ####
           ## ### ########
          ### ##########
         ### ###########
         #################     ######
         ###############       #####      #####
        #####     ######      ##############
      #######       ######################
      #####        ###################
         ##       ###############
               ######
               #######
                  ### \n" + NOR,me);
     message_vision(sprintf(HIR + "魔獸熾血狂獅發出鬼魅般的狂嚎，並無情的吞噬$n！\n" + NOR),me,victim);
     victim->receive_wound("kee",700+random(100),me);
     victim->start_busy(1);
    }
  else
    {
     message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了魂劍五魄"+HIR + "的殺招！\n" + NOR),me,victim);
    }
}
//未完整解迷者部分..
else
{
  message_vision(HIW+HBBLU + "封印在魔劍劍中的五道魂魄飛奔而出，以五魂連星化成一招極殺之招︰『魂劍五魄』\n" + NOR,me,victim);
  for(i=1;i<=3;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf(HIB + "魔劍魂魄╠═ " + HIC + "藍˙糜" + HIB + " ═╣以魔意為劍向$n劈出致命一擊。\n" + NOR),me,victim);
     break;
     case 2:
message_vision(sprintf(HIB + "魔劍魂魄╠═ " + HIR + "紅˙爓" + HIB + " ═╣以殺意為劍向$n劈出致命一擊。\n" + NOR),me,victim);
     break;
     case 3:
message_vision(sprintf(HIB + "魔劍魂魄╠═ " + HIC + "青˙嵐" + HIB + " ═╣以殘意為劍向$n劈出致命一擊。\n" + NOR),me,victim);
     break;
     case 4:
message_vision(sprintf(HIB + "魔劍魂魄╠═ " + HIG + "綠˙魅" + HIB + " ═╣以血意為劍向$n劈出致命一擊。\n" + NOR),me,victim);
     break;
     case 5:
message_vision(sprintf(HIB + "魔劍魂魄╠═ " + HIW + "白˙魂" + HIB + " ═╣以恨意為劍向$n劈出致命一擊。\n" + NOR),me,victim);
     break;
    }
          if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
     {
          message_vision(sprintf(HIC + "魂劍五魄所發出的殺招如鬼怪般無情的吞噬$n！\n" + NOR),me,victim);
          victim->receive_wound("kee",50+random(50),me);
     }
     else
     {
           message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了魂劍五魄"+HIR + "的殺招！\n" + NOR),me,victim);
     }
   }
 }
}
// 第三skill 判斷式 (me->query("swordskill/sword3")==1)
// 將解迷未完成的攻擊力降低而解迷完成則增加攻擊力

void new_3(object me, object victim, object  weapon, int damage)
{
  string aaa;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string ghost2;
  int i,j,force,damage1;
  force=me->query("force",1);
  enemy = me->query_enemy();
  if (me->query("swordskill/sword3")==1) damage1=60;
  else damage1 =10;
  i=random(sizeof(enemy));
// 1/3 機率
  if( random(2) == 0 && me->query("force") > 510 && !me->query_temp("conti",1)) {
  message_vision(sprintf(HIC + "$N殺的興起，眼漏紅光突然大喝《" + HIR + "魔天奧義--葬神九殺" + HIC + "》，一個轉身殺到$n身邊.\n" + NOR),me,victim);
    for(j=0; j < 9; j++) {
     aaa = ghost[j];
       ghost2 = "\n";
       ghost2 += aaa;

       if( weaponn=me->query_temp("weapon") )
       ghost2 = replace_string(ghost2, "$w", weaponn->name());
       message_vision(ghost2, me, enemy[i]);
      if( random(me->query("combat_exp")) > random(enemy[i]->query("combat_exp"))/6 )
       {
        message_vision("\n但是$N閃躲不及，身上頓時多出了一道血淋淋的劍痕。\n" , enemy[i]);
//全中威力約為500
        enemy[i]->receive_damage("kee",damage1+random(30));
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
       }
   else message_vision("\n$N人比劍快，驚險地閃過了這一招。\n",enemy[i]);
                    }

    }
 
}
// 第四skill 判斷式 (me->query("swordskill/sword5")==1)
// 將解迷未完成的攻擊力降低而解迷完成則增加攻擊力
// 血魔殺-水之技
void at_wind_2(object me, object victim, object  weapon, int damage)
{
 int i;
   i=random(4)+1;
 if (!me->query("swordskill/sword5"))
  {
   message_vision(HBBLU + "$N運起渾身血魔鬥氣，但血魔氣勁無法凝聚，因此僅發出些微劍氣！\n" + NOR,me);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(HIC + "$N所發出的殺招輕輕掠過$n身上，造成如蚊蟲叮咬的痕跡！\n" + NOR,me,victim);
     victim->receive_wound("kee",random(100),me);
    }
   else
    {
     message_vision(HIB + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR,me,victim);
    }
  }
 else
 {
  if (i==1)
   {
   message_vision(HIB + "$N運起渾身血魔鬥氣，血魔氣勁迅速凝聚，$N吸收身外紅色血魔氣焰，並由心口冒出駭人之暗藍火光！暗藍火光迅速包覆$N，$N的攻勢也蓄勢待發－－瞬間$N眼泛藍光伴隨身上暗藍氣焰殺出" + HIW + "【" + HBBLU + "血魔殺－湛藍血殺" + NOR + "" + HIW + "】！" + NOR,me,victim);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(HIB + "伴隨$N所發出狂焰氣勁，$n閃躲不及，墬入無情殺招中！\n" + NOR,me,victim);
     victim->receive_wound("kee",500+random(300),me);
     COMBAT_D->report_status(victim);
     COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
   else
    {
     message_vision(sprintf(HIB + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR),me,victim);
    }
   }
   else if (i==2)
   {
   message_vision(HIB + "血魔鬥氣牽動$N渾身殺意，暗藍火光再度串起！$N運勁將凝聚於暗藍氣焰漸漸轉變神龍形式，殺氣瞬間暴漲，" + HIW + "【" + HBBLU + "血魔殺－水爆魔龍擊" + NOR + "" + HIW + "】" + HIB + "，夾帶水龍無比戰意攻向$n！" + NOR,me,victim);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(sprintf(HIB + "水爆魔龍擊一招擊出後，帶動無匹洪水勁，$N隨著無窮氣勁使出" + HIY + "" + HBBLU + "龍躍九天：水魔亂舞" + NOR + "" + HIB + "瞬間對$n刺出無數劍，$n閃躲不及，墬入無情殺招中！\n" + NOR),me,victim);
      victim->receive_wound("kee",500+random(300),me);
      victim->start_busy(1);
     COMBAT_D->report_status(victim);
     COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
  else
    {
     message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR),me,victim);
    }
   }
   else if (i==3)
   {
   message_vision(HIB + "$N雙目緊閉，吸收身邊無數紅色氣焰！遙想大海無量之意，使出一招" + HIW + "【" + HBBLU + "血魔殺－赤紅血潮" + NOR + "" + HIW + "】" + HIB + "除本身無比血氣之外並挾帶大海無量之氣，狂擊$n！" + NOR,me,victim);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(sprintf(HIB + "赤紅血潮一招擊出後，挾帶大海狂嘯之氣，直擊$n，$n閃躲不及，墬入無情殺招中！\n" + NOR),me,victim);
      victim->receive_wound("kee",500+random(300),me);
      victim->start_busy(1);
     COMBAT_D->report_status(victim);
     COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
   else
    {
     message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR),me,victim);
    }
   }
   else if (i==4)
   {
   message_vision(HIB + "$N運起渾身血魔鬥氣，血魔殺氣瘋狂爆射，$N身上因血氣凝聚而散發出紅色氣焰！$N運勁將吸納四周血氣，凝聚於紅色氣焰漸漸往$N身上凝聚，瞬間在$N身後血光大盛，" + HIW + "$N大喊：看我血魔霸劍殺法之" + HIW + "【" + HBBLU + "血魔殺－烈焰寒冰破" + NOR + "" + HIW + "】！！" + HIB + "$N藉由" + HIW + "【" + HBBLU + "血魔殺－烈焰寒冰破" + NOR + "" + HIW + "】" + HIB + "一式夾帶熾熱寒冰勁猛然對$n殺出冰火合併的一擊！\n" + NOR,me,victim);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(sprintf(HIB + "烈焰寒冰破蘊含無限攻勢，$n閃過第一劍但根本無法抵擋接下來的殺招，只能任由$N在他身上畫下無可磨滅的傷痕！\n" + NOR),me,victim);
     victim->receive_wound("kee",700+random(100),me);
     victim->start_busy(1);
     COMBAT_D->report_status(victim);
    }
   else
    {
     message_vision(sprintf(HIB + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR),me,victim);
    }
   }
  }
}
// 第五skill 判斷式 (me->query("swordskill/sword6)==1)
// 將解迷未完成的攻擊力降低而解迷完成則增加攻擊力
// 血魔殺-炎之技

void at_wind_1(object me, object victim, object  weapon, int damage)
{
 int i;
   i=random(3)+1;
 if (!me->query("swordskill/sword6"))
  {
   message_vision(HBBLU + "$N運起渾身血魔鬥氣，但血魔氣勁無法凝聚，因此僅發出些微劍氣！\n" + NOR,me);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(HIC + "$N所發出的殺招輕輕掠過$n身上，造成如蚊蟲叮咬的痕跡！\n" + NOR,me,victim);
     victim->receive_wound("kee",random(100),me);
    }
   else
    {
     message_vision(HIR + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR,me,victim);
    }
  }
 else
 {
  if (i==1)
   {
   message_vision(HIR + "$N運起渾身血魔鬥氣，血魔氣勁迅速凝聚，$N身上因血氣凝聚而散發出紅色氣焰！凝聚於$N深厚的紅色氣焰漸漸成型，$N的攻勢也蓄勢待發－－瞬間$N眼泛紅光伴隨身後紅色氣焰殺出" + HIW + "【" + HBRED + "血魔殺－炙炎狂魔爆" + NOR + "" + HIW + "】！\n" + NOR,me,victim);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(HIR + "伴隨$N所發出狂焰氣勁，$n閃躲不及，墬入無情烈火殺招中，然而炙炎狂魔似乎完全沒有想放過$n的跡象！無情摧殘$n\n" + NOR,me,victim);
     victim->receive_wound("kee",500+random(300),me);
     COMBAT_D->report_status(victim);
     COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
   else
    {
     message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR),me,victim);
    }
   }
   else if (i==2)
   {
   message_vision(HIR + "$N運起渾身血魔鬥氣，血魔氣勁迅速凝聚，$N身上因血氣凝聚而散發出紅色氣焰！\n$N運勁將凝聚於紅色氣焰漸漸轉變鳳凰形式，殺氣瞬間暴漲，" + HIW + "【" + HBRED + "血魔殺－火鳳炎舞" + NOR + "" + HIW + "】" + HIR + "，夾帶火鳳無比戰意攻向$n！\n" + NOR,me,victim);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(sprintf(HIR + "火鳳飛舞後，$N看準時機吸納火鳳熱氣，發出無情烈火氣勁，$n閃躲不及，墬入無情烈火殺招中！\n" + NOR),me,victim);
      victim->start_busy(1);
      victim->receive_wound("kee",500+random(300),me);
     COMBAT_D->report_status(victim);
    }
   else
    {
     message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR),me,victim);
    }
   }
   else if (i==3)
   {
   message_vision(HIR + "$N運起渾身血魔鬥氣，血魔氣勁迅速凝聚，$N身上因血氣凝聚而散發出紅色氣焰！$N運勁將吸納四周血氣，凝聚於紅色氣焰漸漸往$N身上凝聚，瞬間在$N身後血光大盛，\n" + HIW + "$N大喊：看我血魔霸劍殺法之" + HIW + "【" + HBRED + "血魔殺－血陽震天" + NOR + "" + HIW + "】！！\n" + HIR + "$N藉由" + HIW + "【" + HBRED + "血魔殺－血陽震天" + NOR + "" + HIW + "】" + HIR + "一式夾帶無比戰意猛然對$n殺出血陽十六劍！\n" + NOR,me,victim);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(sprintf(HIR + "血陽十六劍蘊含無限攻勢，$n閃過第一劍但根本無法抵擋接下來的殺招，只能任由$N在他身上畫下無可磨滅的傷痕！\n" + NOR),me,victim);
     victim->receive_wound("kee",700+random(100),me);
     COMBAT_D->report_status(victim);
     COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
   else
    {
     message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR),me,victim);
    }
   }
  }
}
// 第六skill 判斷式 (me->query("swordskill/sword7")==1)
// 將解迷未完成的攻擊力降低而解迷完成則增加攻擊力
// 血魔殺-嵐之技
void at_wind_3(object me, object victim, object  weapon, int damage)
{
 int i;
 if (!me->query("swordskill/sword7"))
  {
   message_vision(HBBLU + "$N運起渾身血魔鬥氣，但血魔氣勁無法凝聚，因此僅發出些微劍氣！\n" + NOR,me);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(sprintf(HIC + "$N所發出的殺招如輕輕掠過$n身上，造成如蚊蟲叮咬的痕跡！\n" + NOR),me,victim);
     victim->receive_wound("kee",random(100),me);
    }
   else
    {
     message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR),me,victim);
    }
  }
 else
 {
  i=random(2)+1;
  if (i==1)
   {
   message_vision(HIC + "$N運起渾身血魔鬥氣之嵐字訣，血魔氣勁急速竄動！一招" + HIW + "【" + HBCYN + "血魔殺－血躍嵐舞" + NOR + "" + HIW + "】" + HIC + "忘情殺出！！！\n" + NOR,me);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(HIC + "伴隨$N所發出氣勁，$n閃躲不及，墬入無情狂風殺招中，然而$N的殺招無窮無盡！無情摧殘$n\n" + NOR,me,victim);
     victim->receive_wound("kee",500+random(300),me);
     COMBAT_D->report_status(victim);
     COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
   else
    {
     message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR),me,victim);
    }
   }
   else if (i==2)
   {
   message_vision(HIC + "$N運起渾身血魔鬥氣之嵐字訣，血魔氣勁急速竄動，$N身上因血氣期速竄動而散發出青色氣焰！$N運勁將凝聚於青色氣焰轉變麒麟形式，殺氣瞬間暴漲，" + HIW + "【" + HBCYN + "血魔殺－麒麟滅殺" + NOR + "" + HIW + "】" + HIC + "，夾帶麒麟無比迅速之殺招向$n迎面而至！\n" + NOR,me,victim);
   if( random(me->query("combat_exp")) >random(victim->query("combat_exp"))/6 )
    {
     message_vision(sprintf(HIW + "【" + HBCYN + "血魔殺－麒麟滅殺" + NOR + "" + HIW + "】" + HIC + "一招，牽動" + HBCYN + "邪動風元精英－靳檒" + NOR + "" + HIC + "發出無情狂風氣勁，$n閃躲不及，墬入" + HBCYN + "靳檒" + NOR + "" + HIC + "無情狂風殺招中！\n" + NOR),me,victim);
      victim->start_busy(1);
      victim->receive_wound("kee",500+random(300),me);
     COMBAT_D->report_status(victim);
    }
   else
    {
     message_vision(sprintf(HIR + "千鈞一髮之際$n"+HIR + "避開了$N"+HIR + "的殺招！\n" + NOR),me,victim);
    }
   }
  }
}

// 第七skill 判斷式 (me->query("swordskill/sword4")==1)
// 將解迷未完成的攻擊力降低而解迷完成則增加攻擊力
//
void at_wind(object me, object victim, object  weapon, int damage)
{
   int sp_value;
   if (me->query("swordskill/sword4")==1) sp_value =3*(cor+int1+str+spi+cps+kar);
   else sp_value =3*(cor)+int1+str+spi+cps+kar;
   if(victim->query_temp("conti")!=1  && random(me->query_skill("sword")*2) > random(victim->query_skill("dodge") ))
        {
    message_vision(sprintf(HIY + "$N殺意暴漲，幻化數道分身，腳踩七星，瞬間殺到$n身後，手中長劍瞬時血化," + HIW + "$N大喝：『" + HIR + "血魔霸劍！舉世無雙！暴血魔極殺！！！" + HIW + "』，$N瞬間幻化數道身影，分擊$n\n" + NOR),me,victim);
       victim->set_temp("conti",1);
       me->set_temp("conti",1);
      victim->receive_wound("kee",200+random(300),me);
     COMBAT_D->report_status(victim);
     COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
     call_out("wind",1,me,victim);
        }
   else if(damage > 0 && !victim->query_temp("conti") && random(10) > 5){
{
     message_vision(sprintf(HIC + "$N殺招直取$n，手中長劍似乎擁有生命一般以極為刁鑽的方式直刺$n..\n" + NOR),me,victim);
     victim->receive_wound("kee",sp_value);
}
    message_vision(sprintf(HIC + "$N殺招直取$n，手中長劍似乎擁有生命一般以極為刁鑽的方式直刺$n..\n" + NOR),me,victim);
    victim->recieve_wound("kee",sp_value);
         victim->start_busy(1);
   COMBAT_D->report_status(victim);
message_vision(sprintf(HIC + "$N逆轉的真氣一滯，反而使的身形一滯，$n趁勢攻擊\n" + NOR),me,victim);
// 讓對手有出招機會
 COMBAT_D->do_attack(victim, me, victim->query_temp("weapon"),  TYPE_REGULAR);
           }
}
int wind(object me,object victim)
{
if(!me || !victim) return 1;
if(environment(victim) && victim->query_temp("conti") ==1 && (me->query_skill("sword",1) + me->query_skill("move",1)) > random(victim->query_skill("dodge")) && me->is_fighting())
{
message_vision(sprintf(HBYEL + "$N隨血魔霸劍無情的砍殺著毫無防備的$n\n" + NOR),me,victim);
   if (me->query("swordskill/sword4")==1) victim->add("kee",-1*me->query("max_kee")/12);
   else victim->add("kee",-1*me->query("max_kee")/16);
   me->add("force",-40);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
    if(victim->query_temp("conti")==1 && environment(me) == environment(victim))
     call_out("wind",1,me,victim);
  if(random(me->query_skill("sword",1)+me->query_skill("move",1)) < random(victim->query_skill("dodge",1)))
{
      victim->delete_temp("conti");
      me->delete_temp("conti");
}
return 1;
}
// 第八skill 判斷式 (me->query("swordskill/sword8")==1)
// 無解迷或拜過師無法用連擊
void at_quick(object me, object victim, object  weapon, int damage)
 {
 if (me->query("swordskill/sword8")!=1 ||me->query("swordskill/fsword8")==1)
 {
  message_vision(sprintf(HIR + "血霧片片...然而卻無法凝聚殺意...\n" + NOR),me,victim);
  damage = 4*(cor+int1+str+spi+cps+kar);
  victim->add("kee",-damage);
 }
else
{
   int i,time;
    damage = 6*(cor+int1+str+spi+cps+kar);
 if (!me->query_temp("strike"))
  {
    time = random(cor/8)+random(cps/8);
    me->set_temp("strike",1);
    if (random(cor) > random(10))
    victim->start_busy(1);
    for(i=0;i<=time;i++)
   {
     message_vision(sprintf(NOR + "           " + HBRED + "血霧連天 - 魔意無窮 - 陣陣邪氣 - 層層殺勁\n" + NOR),me,victim);
     victim->add("kee",-damage);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
   }
   me->delete_temp("strike");
  }
 else
  {
   if( me->query_temp("strike")==1 )
   {
    message_vision(sprintf(HIR + "片片血霧...引起無限殺機...\n" + NOR),me,victim);
    damage = 10*(cor+int1+str+spi+cps+kar);
   }
   else
   {
    if (random(cor) > random(10))
    victim->start_busy(1);
    for(i=0;i<=time;i++)
     {
       {
     message_vision(sprintf(NOR + "           " + HBRED + "血霧連天 - 魔意無窮 - 陣陣邪氣 - 層層殺勁\n" + NOR),me,victim);
        victim->receice_damage("kee",-damage);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
       }
       victim->delete_temp("conti");
     }
   }
  }
}
}
string perform_action_file(string action)
{
        return CLASS_D("swordsman")+"/blood_sword/"+action;
 }
