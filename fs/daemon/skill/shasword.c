//中文
//將add("kee")調整為receive_damage的攻擊參數並補上攻擊方之參數 且 取消雙色字 by blazakira 2011/4/18
//調整顏色 by blazakira 2011/7/31

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void berserk(object me, object victim, object  weapon, int damage);
void sp_attack0(object me, object victim, object  weapon, int damage);
void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_att2(object me, object victim, object  weapon, int damage);
void array1();
void drunk();
int kar,cps,str,cor,int1,spi;
int sp_value;

string m1=HIW + "$N" + HIW + "手中長劍虹芒大盛，「劍影連陽」，往$n" + HIW + "直刺而去。\n\n" + NOR;
string *parry_msg = ({
  "\n而$n手中的長劍一橫，一招" + HIB + "『鐵鎖橫江』" + NOR + "勢挾千斤往前一推一送，噹的一聲碰出了點點火花反把$N手中的$w險些震飛！\n" + NOR,
  "\n但$n長劍一轉，順著$N的$w以一招" + HIC + "『順流而下』" + NOR + "往$N的手指削去，$N大驚失色下急忙收招回架\n",
  "\n$n劍走輕靈，手中長劍忽削忽刺一連串的兵器撞擊聲後$n已將$N的快招全部化解！\n",
  HIW + "\n$n" + HIW + "以快制快，$N" + HIW + "快但$n" + HIW + "更快，連續刺出了七七四十九劍織成一道劍網將$N" + HIW + "的招式盡數盪開！\n" + NOR,
});
string *unarmed_parry_msg = ({
  "但是被$n格開了。\n",
  "結果被$n擋開了。\n",
});

//劍陣;roger苦思三天三夜所創
//idea 版權所有;模仿必翻臉

void array1()
{
  object me=this_player();
  int number,i,j,m,n,hurt,mean=0,k=0,sha_mean=0,get_sha=0;
  object *partner,*target;

  partner=me->query_team();
  number=sizeof(partner);
  target=me->query_enemy();
  i=sizeof(target);
  if(i < 1 ) return ;
  if(!number) return ;
  for(j=0;j<number;j++) {
    if((environment(partner[j]) == environment(me)) && partner[j]->query_temp("use_form")==1) {
      sha_mean=sha_mean+partner[j]->query_skill("shasword",1);
      k=k+1;
    }
  }

  for(j=0;j<number;j++) {
    if(partner[j]->query("get_sha_sp")==1)
      get_sha=get_sha+1;
  }
  sha_mean=sha_mean/number;
  for(j=0;j<number;j++) {
    mean=mean+(partner[j]->query_skill("array"));
  }
  mean=mean/number;

  if(k==2) {
    if(random(100) > 82 && mean < 75) {
      hurt=mean*1.4*2;
      message_vision("\n" + HIM + "$N" + HIM + "一聲清嘯，陣形一轉和$n" + HIM + "聯手使出陰陽兩儀劍陣的絕招。" + NOR+
        "\n---" + HBWHT+HIM + "鶴" + HBMAG+HIW + "翔" + HBWHT+HIM + "紫" + HBMAG+HIW + "薇" + NOR + "---\n"+
        HIM + "$N" + HIM + "大喝一聲，劍尖閃出了耀眼紫光，敵人為之一時無法睜開眼睛而同時只見$n" + HIM + "滿場遊走，動作如仙鶴般優雅輕靈，"+
        "陣內敵人已在同時全部受到了重創！\n\n" + NOR,partner[0],partner[1]);
      for(j=0;j<i;j++) {
        target[j]->receive_damage("kee",hurt,me);
        COMBAT_D->report_status(target[j], 1);
      }
    }

    else if(random(100) > 82 && mean >= 75) {
      hurt=mean*1.9*2;
      message_vision(HIR + "\n$N" + HIR + "和$n" + HIR + "心意相通，使出了陰陽兩儀陣法的精髓---"+
        HIR + "『" + HIM + "二劍穿腸紅" + HIR + "』\n$N" + HIR + "和$n" + HIR + "同時縱身一躍，以極快的速度依著陣法移動身形剎那間兩儀陣內紅影穿梭，陰中有陽，陽中有陰...\n" + NOR+
        "結果陣內的敵人不知如何防禦，紛紛被劍氣所傷。\n\n",partner[0],partner[1]);
      for(j=0;j<i;j++) {
        target[j]->receive_damage("kee",hurt,me);
        COMBAT_D->report_status(target[j], 1);
      }
    }

    else if(random(100) > 80) {
      message_vision(HIG + "$N" + HIG + "和$n" + HIG + "不停的移行換位，陰變陽，陽轉陰，使敵人看得眼花撩亂。\n" + NOR,partner[m],partner[m+1]);
    }
  }

  else if(k==3) {
    if(random(100) > 82) {
      if(mean >= 75 && get_sha==3) {
        hurt=mean*2.2*3;//三人皆有後三 && sha-array 平均大於75 所以威力上調
        message_vision(HIY + "陣內三才忽然心意相通，不約而同各使出仙劍後三式中的一招，融合成此曠世絕招"+
          HIW + "------" + HIY + "仙劍後三合一式" + HIW + "------\n\n"+
          "$N" + HIW + "使出仙劍後三式之第一招\n"+
          "----" + HBBLU+HIC + "冰" + HBCYN+HIB + "若" + HBBLU+HIC + "寒" + HBCYN+HIB + "潭" + NOR+HIW + "---\n"+
          "$N" + HIW + "以氣行劍，瞬時間一股寒氣籠罩身旁，只見劍上薄冰漸起幻成冰柱，$N" + HIW + "手中長劍橫掃，只見冰柱隨劍氣朝敵人猛裂刺去——\n"+
          "敵人瞬間被刺傷多處...\n",partner[0]);
        message_vision("\n"+HIW + "$N" + HIW + "使出仙劍後三式之第二招\n"+
          "----" + HBRED+HIR + "萬" + HBMAG+HIM + "丈" + HBRED+HIR + "波" + HBMAG+HIM + "瀾" + NOR+HIW + "---"+
          "$N" + HIW + "手中長劍急使，愈使愈快，宛若洶湧巨浪向敵人直衝而去，瞬時壓力遽增，\n"+
          "敵人被巨浪震出內傷，鮮血狂噴....\n",partner[1]);
        message_vision("\n" + HIW+
          "$N" + HIW + "使出仙劍後三式之第三招\n"+
          "----" + HBYEL+HIG + "雲" + HBGRN+HIY + "譎" + HBYEL+HIG + "波" + HBGRN+HIY + "詭" + NOR+HIW + "---\n"+
          "$N" + HIW + "長劍飛舞，霎時四周水波雲氣變化萬千難以預料，敵人瞬間分不清劍在何方，\n"+
          "正在遲疑之際，劍已穿體而出....\n\n"+
          HIY + "三招合一的威勢驚人，一股強大的劍氣在陣內衝撞，敵人非死即傷！\n" + NOR,partner[2]);
        for(j=0;j<i;j++) {
          target[j]->receive_damage("kee",hurt,me);
          COMBAT_D->report_status(target[j], 1);
        }
      }

      else {
        hurt=mean*1.5*3;
        message_vision(HIY + "\n三才劍陣內祥光隱隱，劍陣絕招" + HIW + "『" + HIY + "鱗光三劍" + HIW + "』" + HIY + "依三才特性之氣騰出！\n"+
          "$N" + HIY + "引導三種祥光在陣內流轉，繽紛奪目，傷人於炫麗之中......\n\n" + NOR,partner[0]);
        for(j=0;j<i;j++) {
          target[j]->receive_damage("kee",hurt,me);
          COMBAT_D->report_status(target[j], 1);
        }
      }
    }

    else if(random(100) > 80) {
      message_vision(HIY + "$N" + HIY + "指揮若定，天地人三位配合一體防守得固若金湯\n" + NOR,partner[0]);
    }
  }

  else if(k==4) {
    if(random(100) > 79) {
      if(mean >= 75 && sha_mean >= 95) {
        //曠世絕招，四人皆要有雙十才行，很懷疑能不能有機會用...
        hurt=mean*3.1*4;
        message_vision(HIB + "\n陣內四人心意忽然頓悟，決定以身一試期望能融合出曠世絕招" + HIY + "『" + HIB + "四龍崩月" + HIY + "』" + HIB + "!!!\n\n" + HIW + "只見陣內四人同時仰天長嘯，一齊使出仙劍至極之招" + HIR + "『 雙～十～旋～龍～斬 』" + HIB + "!!!\n\n" + HIB + "四條青龍從四個人的劍尖衝出，在空中不停地聚合盤旋，剎那間!!!天地變色，\n"+
          "風起雲湧。一輪" + HIY + "明月" + HIB + "在龍雲之間現形，而敵人也被此情景所震懾，一瞬間已\n"+
          "被吞沒於光芒之中。\n\n" + NOR,partner[0]);
        for(j=0;j<i;j++) {
          target[j]->receive_damage("kee",hurt,me);
          target[j]->start_busy(1);
          COMBAT_D->report_status(target[j], 1);
        }
      }

      else {
        hurt=mean*1.7*4;
        message_vision(HIC + "\n眾劍士忽然四劍齊出，使出四象璇磯劍陣的絕招" + HIB + "『" + HIC + "四劍八達" + HIB + "』" + HIC + "，颼颼聲響處兩劍直指\n"+
          "敵人的胸前，同時另兩劍從左右分刺。當敵人想予以招架時四劍又同時分擊合刺，威\n"+
          "力實在驚人！\n\n" + NOR,partner[0]);
        for(j=0;j<i;j++) {
          target[j]->receive_damage("kee",hurt,me);
          target[j]->start_busy(1);
          COMBAT_D->report_status(target[j], 1);
        }
      }
    }

    else if(random(100) > 80) {
      message_vision(HIB + "$N" + HIB + "以全力運轉四象璇磯陣，將敵人牢牢的困在陣中。\n" + NOR,partner[0]);
    }
  }

  //八人陣極難組成，需八個仙劍高手，主陣者亦需神200 and sha-array >=80
  //so 威力加強
  else if(k==8) {
    if(random(100) >= 75) {
      message_vision(HIG + "\n$N" + HIG + "仰天長嘯，催動八卦遊龍陣使出驚世駭俗的仙劍劍陣至極絕招\n\n"+
        "                     " + HIW + "『" + HIR + "～禁～斷～連～陽～七～訣～斬" + HIW + "』" + NOR + "\n\n" + HIR + "此招一出，驚天動地，傳說自仙劍創派以來從未被使用過!!\n",partner[0]);
      message_vision(sprintf(HIB + "\n$N" + HIB + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第一式" + HIW + "『" + HIB + "烈陽" + HIW + "』" + HIB + "!!\n" + NOR ),partner[1]);
      message_vision(sprintf(HIR + "\n$N" + HIR + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第二式" + HIW + "『" + HIR + "殘陽" + HIW + "』" + HIR + "!!\n" + NOR ),partner[2]);
      message_vision(sprintf(HIW + "\n$N" + HIW + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第三式" + HIW + "『豔陽』!!\n" + NOR),partner[3]);
      message_vision(sprintf(HIM + "\n$N" + HIM + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第四式" + HIW + "『" + HIM + "暖陽" + HIW + "』" + HIM + "!!\n" + NOR),partner[4]);
      message_vision(sprintf(HIC + "\n$N" + HIC + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第五式" + HIW + "『" + HIC + "冬陽" + HIW + "』" + HIC + "!!\n" + NOR),partner[5]);
      message_vision(sprintf(HIG + "\n$N" + HIG + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第六式" + HIW + "『" + HIG + "朝陽" + HIW + "』" + HIG + "!!\n" + NOR),partner[6]);
      message_vision(sprintf(HIY + "\n$N" + HIY + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第七式" + HIW + "『" + HIY + "夕陽" + HIW + "』" + HIY + "!!\n" + NOR), partner[7]);
      message_vision(HIW + "\n七道劍虹同時激空而出，「七陽連天」在空中織成一道虹網！\n" + HIG + "而主陣的$N" + HIG + "縱身一躍，凝氣準備發出最後一式以完成這驚天地動的一擊！\n" + NOR,partner[0]);
      message_vision(sprintf(HIW + "\n只見$N" + HIW + "狂性驟起，大喝一聲『" + HIR + "劍影連陽，七陽連天" + HIW + "』!!\n" + NOR),partner[0]);
      message_vision(HIW + "$N" + HIW + "的七陽連天氣勢澎礡，激發了先前仙劍禁斷之連陽七訣的七股剛柔不等的劍虹，只見虹氣嘯天，滿天劍影，陣內敵人全都受到了重創\n" + NOR,partner[0]);
      for(j=0;j<i;j++) {
        target[j]->receive_damage("kee",800,me);
        target[j]->start_busy(2);
        COMBAT_D->report_status(target[j], 1);
      }
    }

    else if(random(100) > 60) {
      message_vision(HIM + "$N" + HIM + "指揮八卦遊龍陣內的劍士不停地移行換位，氣勢萬千！\n" + NOR,partner[0]);
    }
  }

}
//劍陣;roger苦思三天三夜所創
//idea 版權所有;模仿必翻臉:P

void drunk()
{
  object me=this_player();
  int number,i,j,me_lv,tar_lv;
  object *target;
  target=me->query_enemy();
  i=sizeof(target);
  j=random(i);
  me_lv=me->query_skill("dodge");
  me_lv*=1.3;
  tar_lv=target[j]->query_skill("dodge");
  if(me->query_skill("shasword",1) > 70&&me->query_skill("sha-steps",1)>50&&!me->query_temp("conti",1))
  {
    message_vision("\n$N醉吟道：\n"+
      HIW + "　　『御劍乘風來，除魔天地間。有酒樂逍遙，無酒我亦顛。\n"+
      "　　　一飲盡江河，再飲吞日月。千杯醉不倒，唯我" + HIR+me->query("name")+HIW + "』\n" + NOR+
      "使出一招" + HIW + "『" + HIR + "橫醉千秋" + HIW + "』" + NOR + "，乘著酒意將仙劍劍術發揮得淋漓盡致。\n",me);
     if(me_lv > tar_lv) {
       message_vision("\n$N閃避不及，被這招當胸刺中。\n",target[j]);
       target[j]->receive_damage("kee",250,me);
       COMBAT_D->report_status(target[j]);
       me->add("force",-30);
     }
     else message_vision("\n$N縱身躍起，及時閃過了這一招。\n",target[j]);
  }
}

mapping *action = ({
//1
  ([
    "action"     :  "$N手捏劍訣，長劍一挺，使出一招" + HIC + "『泉鳴芙蓉』" + NOR + "，姿態悠雅，頗有天上仙人下凡間之意。",
    "dodge"      :  -10,
    "parry"      :  -10,
    "damage"     :  40,
    "force"      :  40,
    "damage_type":  "刺傷"
  ]),
//2
  ([
    "action"     :  "$N一個旋身，手中的$w在空中閃過一道光芒直刺向$n的$l，姿態瀟灑一氣呵成，正是一招" + HIY + "『金雁橫空』" + NOR + "。",
    "dodge"      :  0,
    "parry"      :  0,
    "damage"     :  80,
    "force"      :  80,
    "damage_type":  "刺傷"
  ]),
//3
  ([
    "action"     :  "$N左肩微沉，左手劍訣斜引，右肘一縮，使出一招" + HIM + "『有鳳來儀』" + NOR + "劍勢迅速凌厲直往$n的$l刺去。",
    "dodge"      :  10,
    "parry"      :  10,
    "damage"     :  100,
    "force"      :  100,
    "damage_type":  "刺傷"
  ]),
//4
  ([
    "action"     :  "$N劍勢一改往常的飄逸絕倫，使出一招" + HIW + "『" + HIY + "玉碎仙岡" + HIW + "』" + NOR + "直削橫劈、氣勢威猛的往$n身上大力斬去。",
    "dodge"      :  20,
    "parry"      :  20,
    "damage"     :  150,
    "force"      :  150,
    "damage_type":  "割傷"
  ]),
//5
  ([
    "action"     :  "$N劍勢大開大闔，使出一招" + HIC + "『劈竹掃影』" + NOR + "狂風暴雨般的招式使$n感到難以招架。",
    "dodge"      :  30,
    "parry"      :  30,
    "damage"     :  170,
    "force"      :  170,
    "damage_type":  "割傷"
  ]),
//6
  ([
    "action"     :  "$N劍尖連劃出幾個劍花，一招" + HIW + "『飄雲穿雪』" + NOR + "如浮雲般飄逸，化成片片白雪緩緩落於$n的身上。",
    "dodge"      :  30,
    "parry"      :  20,
    "damage"     :  200,
    "force"      :  200,
    "damage_type":  "刺傷"
  ]),
//7
  ([
    "action"     :  "$N將手中的$w斜引，使出一招" + HIW + "『峭壁斷雲』" + NOR + "，劍勢雄偉精奇氣勢縱橫使$n感到左支右拙難以招架。",
    "parry"      :  30,
    "dodge"      :  40,
    "damage"     :  220,
    "force"      :  220,
    "damage_type":  "割傷",
  ]),
//8
  ([
    "action"     :  "$N真氣灌於手中的$w，使出一招" + HIR + "『飛虹橫江』" + NOR + "頓時劍尖衝出半尺來長的紅色劍芒，吞吐閃爍，嗤嗤聲響處往$n疾刺而去。",
    "parry"      :  30,
    "dodge"      :  40,
    "damage"     :  240,
    "force"      :  240,
    "post_action":  (: berserk :),
    "damage_type":  "割傷",
  ]),
//9
  ([
    "action"     :  "$N手中的$w一閃出鞘，寒芒吞吐，電閃星爍，一招" + HIB + "『寒芒沖霄』" + NOR + "劍氣化成點點寒芒往$n身上飛去。",
    "dodge"      :  50,
    "parry"      :  30,
    "damage"     :  260,
    "force"      :  260,
    "post_action":  (: berserk :),
    "damage_type":  "刺傷",
  ]),
//10
  ([
    "action"     :  "$N一聲清嘯，手中長劍抖動處數以百計的玉色光芒從$N的劍尖疾飛而出，燦爛如銀河飛濺，正是一招" + HIW + "『" + HIY + "盡傾銀河" + HIW + "』" + NOR + "！",
    "dodge"      :  60,
    "parry"      :  30,
    "damage"     :  280,
    "force"      :  280,
    "damage_type":  "刺傷",
  ]),
//11
  ([
    "action"     :  "$N使出仙劍派之絕招" + HIG + "『隔紙斷樹』" + NOR + "，手中的$w虛劃，$n愕然不明所以之際不知自己筋脈已被斬斷...",
    "dodge"      :  60,
    "parry"      :  40,
    "damage"     :  300,
    "force"      :  300,
    "post_action":  (: berserk :),
    "damage_type":  "筋脈盡斷",
  ]),
//12
  ([
    "action"     :  "$N劍泛仙氣，聚精會神地使出了仙劍劍術中的最高境界" + HIY + "『仙傾霜天』" + NOR + "！劍由仙化，使劍若仙，金光閃耀下$n全身已被割傷多處...",
    "parry"      :  40,
    "dodge"      :  70,
    "damage"     :  300,
    "force"      :  300,
    "damage_type":  "心劍之傷",
  ]),
//13
  ([
    "action"     :  "$N使出仙劍後三式之第一招\n"+
                    "----" + HBBLU+HIC + "冰" + HBCYN+HIB + "若" + HBBLU+HIC + "寒" + HBCYN+HIB + "潭" + NOR + "---\n"+
                    "$N以氣行劍，瞬時間一股寒氣籠罩身旁，只見劍上薄冰漸起幻成冰柱，$N手中長劍橫掃，只見冰柱隨劍氣朝$n猛裂刺去，\n"+
                    "$n瞬間被刺傷多處...\n",
    "dodge"      :  50,
    "parry"      :  80,
    "damage"     :  400,
    "force"      :  400,
    "post_action":  (: sp_attack0 :),
    "damage_type":  "刺傷",
  ]),
//14
  ([
    "action"     :  "$N使出仙劍後三式之第二招\n"+
                    "----" + HBRED+HIR + "萬" + HBMAG+HIM + "丈" + HBRED+HIR + "波" + HBMAG+HIM + "瀾" + NOR + "---\n"+
                    "$N手中長劍急使，愈使愈快，宛若洶湧巨浪向$n直衝而去，瞬時壓力遽增，\n"+
                    "$n被巨浪震出內傷，鮮血狂噴...\n",
    "dodge"      :  50,
    "parry"      :  80,
    "damage"     :  400,
    "force"      :  400,
    "post_action":  (: sp_attack1 :),
    "damage_type":  "砍傷",
  ]),
//15
  ([
    "action"     :  "$N使出仙劍後三式之第三招\n"+
                    "----" + HBYEL+HIG + "雲" + HBGRN+HIY + "譎" + HBYEL+HIG + "波" + HBGRN+HIY + "詭" + NOR + "---\n"+
                    "$N長劍飛舞，霎時四周水波雲氣變化萬千難以預料，$n瞬間分不清劍在何方，\n"+
                    "正在遲疑之際，劍已穿體而出...\n",
    "dodge"      :  50,
    "parry"      :  80,
    "damage"     :  400,
    "force"      :  400,
    "post_action":  (: sp_att2 :),
    "damage_type":  "砍傷",
  ]),
//16
  ([
    "action"     :  "\n$N低吟道：\n"+
      "               " + HIG + "『" + HIW + "斬風截雪破千秋               初冬舞塵一朝仇\n"+
      "                 笑任青天縱豪情               劍狂情狂人更狂" + HIG + "』\n" + NOR+
      "吟罷舞劍而起，使出了仙劍派的殺招" + HIW + "『" + HBWHT+HIG + "碧" + HBGRN+HIW + "波" + HBWHT+HIG + "殺" + HBGRN+HIW + "機" + HBWHT+HIG + "映" + NOR+HIW + "』" + NOR + "！\n" + HIG+
      "招如其名，在$N" + HIG + "長劍舞動下碧綠劍氣縱橫宛如陣陣波濤，卻掩不住暗藏其中的殺意。\n" + NOR,
    "dodge"      :  60,
    "parry"      :  50,
    "damage"     :  320,
    "force"      :  320,
    "post_action":  (: berserk :),
    "damage_type":  "割傷",
  ]),
//17
  ([
    "action"     :  "\n$N回劍入鞘，緩緩說道：\n"+
      "              " + HIW + "『" + HIR + "一蕭一劍平生意               負盡狂名殺無情" + HIW + "』\n" + NOR+
      "說罷眼中殺意陡盛，拔劍出鞘，使出了仙劍派禁招" + HIW + "『" + HBWHT+HIR + "落" + HBRED+HIW + "日" + HBWHT+HIR + "殘" + HBRED+HIW + "情" + HBWHT+HIR + "滅" + NOR+HIW + "』" + NOR + "！\n" + HIR+
      "$N迅速地揮動手中的$w" + HIR + "，只見滿天血紅宛若落日的餘暉，卻原來是$n" + HIR + "被殺招所傷，滿身鮮血飛揚於空中！\n" + NOR,
    "dodge"      :  60,
    "parry"      :  50,
    "damage"     :  340,
    "force"      :  340,
    "post_action":  (: berserk :),
    "damage_type":  "割傷",
  ]),
//18
  ([
    "action"     :  HIG + "$N" + NOR+HIG + "眉頭緊鎖，愁上心頭不禁仰天長嘆一聲，使出了" + HIW + "『" + HBYEL+HIG + "秋" + HBGRN+HIY + "意" + HBYEL+HIG + "愁" + HBGRN+HIY + "無" + HBYEL+HIG + "限" + NOR+HIW + "』\n"+
      HIG + "$N" + HIG + "拔劍出鞘，秋風颯颯，手中的$w" + HIG + "在$n" + NOR+HIG + "的四周化為片片落葉，瞬時間$n" + NOR+HIG + "已被割傷多處..." + NOR,
    "dodge"      :  60,
    "parry"      :  50,
    "damage"     :  360,
    "force"      :  360,
    "post_action":  (: berserk :),
    "damage_type":  "割傷",
  ]),
//19 
  ([
    "action"     :  HIY + "$N" + NOR+HIY + "心中怒意急升，決定使出仙劍派之禁招---" + HIY + "『" + HBWHT+HIY + "黃" + HBYEL+HIW + "沙" + HBWHT+HIY + "怒" + HBYEL+HIW + "音" + HBWHT+HIY + "揚" + NOR+HIY + "』！\n"+
      "$N" + NOR+HIY + "運劍如風，劍氣縱橫激起地面滾滾塵沙，宛若千軍萬馬馳騁般往$n" + NOR+HIY + "暴擊而去。" + NOR,
    "dodge"      :  60,
    "parry"      :  50,
    "damage"     :  380,
    "force"      :  380,
    "post_action":  (: berserk :),
    "damage_type":  "割傷",
  ]),
//20
  ([
    "action"     :  HIW + "$N" + NOR+HIW + "突感心中之悲意，驀然使出了" + HIW + "『" + HBWHT+HIB + "寒" + HBBLU+HIW + "夜" + HBWHT+HIB + "孤" + HBBLU+HIW + "星" + HBWHT+HIB + "墜" + NOR+HIW + "』！\n"+
      "$N" + NOR+HIW + "縱身而起，一個倒仰竟從空中向$n" + NOR+HIW + "倒刺而下，此招全然不顧己身可見施展之人心中之悲意及殺意實已到達的極點。\n"+
      "而$n" + NOR+HIW + "看到此招如此施展竟嚇得面如土色，已經不知如何招架！\n" + NOR,
    "dodge"      :  60,
    "parry"      :  50,
    "damage"     :  400,
    "force"      :  400,
    "post_action":  (: berserk :),
    "damage_type":  "刺傷",
  ]),

//21 enforce >10 不能用
  ([
    "action"     :  "$N運力過度，無法使出仙劍劍術。",
    "force"      :  10,
    "damage"     :  1,
    "damage_type":  "白癡傷",
  ]),
});


int valid_learn(object me)
{
  if( !me->query_temp("weapon") )
    return notify_fail("練仙劍劍術必需先拿把劍。\n");
  return 1;
}

int valid_enable(string usage)
{
  return ( usage=="sword" || usage=="parry" );
}

mapping query_action(object me, object *weapon)
{
  int skill_level,limit,i,bellicosity;
  object victim,*enemy;
  kar=me->query_kar();
  cps=me->query_cps();
  str=me->query_str();
  cor=me->query_cor();
  int1=me->query_int();
  spi=me->query_spi();

  enemy = me->query_enemy();
  i=sizeof(enemy);
  weapon=me->query_temp("weapon");
  skill_level = (int)(me->query_skill("shasword",1));
  limit= skill_level;
  bellicosity = (int)(me->query("bellicosity",1));
  if(userp(me) && me->query("force_factor") >= 16 && me->query("family/family_name")!="仙劍派")
    return action[0];
  while(i--)
  {
    if(skill_level >= 95 && (me->query("family/family_name")=="仙劍派") && me->query("id")!="murofu" && me->query("name")!="慕容復"&& me->query("force",1) > 200 && random(100) > 65)
    {
      message_vision(sprintf(HIW + "\n\n只見$N" + HIW + "仰天長嘯，使出仙劍至極之招" + HIR + "『 雙～十～旋～龍～斬 』" + HIW + "!!!" + NOR),me,enemy[i]);
      message_vision(sprintf(HIB + "\n$N" + HIB + "不停地飛舞著劍，其身形漸漸地化為龍形，剎那間!!天地為之變色，四周草木皆非，\n"+
        "$n" + HIB + "也被這股氣勢震嚇住，一瞬間$n" + HIB + "已遭龍所吞噬。\n\n" + NOR),me,enemy[i]);
      if(weapon->query("id")=="silver sword" || weapon->query("id")=="ssad sword") {
        message_vision(HIW + "\n$N" + HIW + "的銀鱗古劍感應到" + HIR + "『 雙～十～旋～龍～斬 』" + HIW + "的驚人氣勢，劍上的銀鱗白光\n"+
          "閃耀下化成一道龍形劍氣直撲向$n" + HIW + "。\n" + NOR,me,enemy[i]);
        enemy[i]->receive_wound("kee",500,me);
        COMBAT_D->report_status(enemy[i]);
        enemy[i]->start_busy(1);
        me->add("force",-180);
      }

      else{
        enemy[i]->receive_wound("kee",400,me);
        COMBAT_D->report_status(enemy[i]);
        me->add("force",-90);
      }
    }
  }

  if( me->is_team_leader() && me->query_temp("use_form")==1) 
    array1();
                                  
  if(me->query_condition("drunk",1) > 0 && random(5)==0) drunk();

  if (limit < 10)
    return action[random(2)];
  else if (limit < 20)
    return action[random(4)];
  else if (limit < 30)
    return action[random(5)];
  else if (limit < 40)
    return action[random(5)+1];
  else if (limit < 50)
    return action[random(5)+2];
  else if (limit < 60)
    return action[random(5)+3];
  else if (limit < 70)
    return action[random(5)+4];
  else if (limit < 80)
/*下面這行一直讓npc沒心跳,請appo查明原因 by bss
    return action[random(5)+5];
*/
    return action[random(5)+5];
  if( me->query("family/family_name")!="仙劍派" || !me->query("get_sha_sp",1) )
  {
    if (limit < 85)
      return action[random(5)+6];
    else if (limit < 90)
      return action[random(5)+7];
    else if(limit >= 90 && bellicosity >= 1000)
      return action[random(5)+15];
    else
      return action[random(5)+7];
  }
  else
  {
    if (limit < 90)
      return action[random(8)+7];
    else if(limit >= 90 && bellicosity >= 1000)
      return action[random(8)+12];
    else
      return action[random(8)+7];
  }
}

//以下三招因為沒更動武器所以暫時不更動 by blazakira
void sp_attack0(object me, object victim, object  weapon, int damage)
{
  sp_value =4*(cps+kar)+str+cor+spi+int1;
  if(sp_value > 400) sp_value=400;
  if( weapon->query("id")=="han_bin_sword" ||weapon->query("id")=="ssad sword")
  {
    message_vision("\n?H?B?C" + HIC + "劍上寒氣與" + NOR + "$N" + HIC + "體內寒勁會合，霎時四周溫度遽降，一股\n陰寒內勁由$N" + HIC + "手中長劍發出朝$n" + HIC + "而去。\n" + NOR,me,victim);
    victim->receive_damage("kee",sp_value,me);
    COMBAT_D->report_status(victim, 1);
  }

  else
  {
    message_vision("$N一運勁一道寒氣發自$N的體內，藉由手中長劍斬向$n。\n",me,victim);
    victim->receive_damage("kee",sp_value/2,me);
    COMBAT_D->report_status(victim, 1);
  }
}

void sp_attack1(object me, object victim, object  weapon, int damage)
{
    int i;
    sp_value =4*(str+cor)+cps+kar+spi+int1;
    if(sp_value > 400) sp_value=400;
    if( weapon->query("id")=="hon_water_sword" || weapon->query("id")=="ssad sword" )
    {
      message_vision("?l???C" + HIW + "蘊含水勁磅礡，與此招式精義吻合，一股柔似水又強如浪的內勁已由" + NOR + "$N" + HIW + "發出直向$n" + HIW + "而去。\n" + NOR,me,victim);
      victim->receive_damage("kee",sp_value,me);
      COMBAT_D->report_status(victim, 1);
    }
    else
    {
      if(!me->query_temp("conti",1))
        {
         message_vision("藉由此招的精義，你感到一股前所未有力量由你體內源源而出，一招招攻向對方\n",me,victim);
         me->set_temp("conti",1);
         for(i=0;i<=2;i++)
           COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
         me->delete_temp("conti");
        }
    }
}

void sp_att2(object me, object victim, object  weapon, int damage)
{
  if( weapon->query("id")=="han_thon_sword" || weapon->query("id")=="ssad sword")
  {
    message_vision("?H???C劍勢迥異難測，加上第三招之變幻莫測，$n一個不留神中了$N 一記強擊且暫時無法對$N展開攻擊。\n",me,victim);
    victim->receive_damage("kee",400,me);
    victim->start_busy(1);
    COMBAT_D->report_status(victim, 1);
  }
  else
  {
    message_vision("$N招式突然千變萬化，手中長劍如蛇般揮向敵人，$n摸不清$N的動向，冷不防的中了一劍。\n",me,victim);
    victim->receive_damage("kee",200,me);
    COMBAT_D->report_status(victim, 1);
  }
}

void berserk(object me, object victim, object  weapon, int damage)
{
  int skill_level=me->query_skill("shasword",1);
  if( random(100) > 70 && me->query("force",1) > 100)
  {
    if(!me->query_temp("conti"))
    {
      if( me->query("family/master_name")=="鄭士欣" || me->query("name")=="鄭士欣"|| me->query("dragon-sword",1)==1 )
      {
        message_vision(sprintf(HIW + "\n只見$N" + HIW + "狂性驟起，大喝一聲『" + HIR + "劍影連陽 七陽連天" + HIW + "』!!\n"),me,victim);
        message_vision(sprintf(HIW + "七股剛柔不等的虹色劍氣驀地由$N" + HIW + "劍尖射出對$n" + HIW + "造成難以估計的傷。\n\n "),me,victim);
        victim->receive_wound("kee",400,me);
        COMBAT_D->report_status(victim, 1);
        me->add("force",-80);
      }else if( me->query("family/master_name")=="張乘風" || me->query("sha-stop-1",1))
      {
        message_vision(sprintf(HIW + "\n$N" + HIW + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第一式『" + HIR + "烈陽" + HIW + "』!!\n" + NOR ),me,victim);
        message_vision(sprintf(m1),me,victim);
        victim->receive_wound("kee",300,me);
        COMBAT_D->report_status(victim, 1);
        me->add("force",-40);
      }else if( me->query("family/master_name")=="張乘雲" || me->query("sha-stop-2",1))
      {
        message_vision(sprintf(HIW + "\n$N" + HIW + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第二式" + HIW + "『" + HIR + "殘陽" + HIW + "』!!\n" + NOR ),me,victim );
        message_vision(sprintf(m1), me, victim );
        victim->receive_wound("kee",300,me);
        COMBAT_D->report_status(victim, 1);
        me->add("force",-40);
      }else if( me->query("family/master_name")=="唐鈺" || me->query("sha-stop-3",1) )
      {
        message_vision( sprintf(HIW + "\n$N" + HIW + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第三式" + HIW + "『" + HIY + "豔陽" + HIW + "』!!\n" + NOR),me,victim);
        message_vision(sprintf(m1), me,victim);
        victim->receive_wound("kee",300,me);
        COMBAT_D->report_status(victim, 1);
        me->add("force",-40);
      }else if( me->query("family/master_name")=="趙鶴" || me->query("sha-stop-4",1))
      {
        message_vision(sprintf(HIW + "\n$N" + HIW + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第四式" + HIW + "『" + HIY + "暖陽" + HIW + "』!!\n" + NOR),me,victim);
        message_vision( sprintf(m1),me,victim);
        victim->receive_wound("kee",300,me);
        me->add("force",-15);
      }else if( me->query("family/master_name")=="梅影" || me->query("sha-stop-5",1))
      {
        message_vision(sprintf(HIW + "\n$N" + HIW + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第五式" + HIW + "『" + HIC + "冬陽" + HIW + "』!!\n" + NOR),me,victim);
        message_vision(sprintf(m1),me,victim);
        victim->receive_wound("kee",300,me);
        COMBAT_D->report_status(victim, 1);
        me->add("force",-10);
      }else if(me->query("family/master_name")=="何雙雙" || me->query("sha-stop-6",1))
      {
        message_vision( sprintf(HIW + "\n$N" + HIW + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第六式" + HIW + "『" + HIY + "朝陽" + HIW + "』!!\n" + NOR),me,victim );
        message_vision(sprintf(m1),me,victim );
        victim->receive_wound("kee",300,me);
        COMBAT_D->report_status(victim, 1);
        me->add("force",-10);
      }else if( me->query_skill("shasword",1) >=60 ||  me->query("sha-stop-7",1))
// 給改拜player 的人用 
      {
        message_vision( sprintf(HIW + "\n$N" + HIW + "狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第七式" + HIW + "『" + HIY + "夕陽" + HIW + "』!!\n" + NOR),me,victim );
        message_vision(sprintf(m1),me,victim );
        victim->receive_wound("kee",300,me);
        COMBAT_D->report_status(victim, 1);
        me->add("force",-30);
      }
    }
  }
}

string query_parry_msg(string limb)
{
  object me=this_player();
  object weapon;

  if(!me)
    return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
  weapon=me->query_temp("weapon");
  if(weapon && weapon->query("skill_type")=="sword")
    return parry_msg[random(sizeof(parry_msg))];
  else 
    return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int practice_skill(object me)
{
  if( (int)me->query("kee") < 40 )
    return notify_fail("你的體力不夠了﹐休息一下再練吧。\n");
  if( (int)me->query("force") < 5 )
    return notify_fail("你的內力不夠了﹐休息一下再練吧。\n");
  me->receive_damage("kee", 40,me);
  me->add("force", -5);
  return 1;
}

string perform_action_file(string action)
{
  return CLASS_D("swordsman")+"/shasword/"+action;
}

