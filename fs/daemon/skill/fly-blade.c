// Edit by pzp
// copy from appo (經過pzp 同意) 請勿在翻版.. !!
// 苦思而成之刀道之境 version 1.0
// 不可翻板
// version 2.0 萬般接諸於刀意
// 前九招之post_action 威力調弱 主攻放在七式刀意
//增加玩家 對手 是否陣亡或離線的判斷 by blazakira 2011/3/12
//補上receive_xxx攻擊方的參數 by blazakira 2011/8/23

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void gold_fluid(object me, object victim, object weapon, int damage);
void light(object me, object victim, object weapon, int damage);
void back_blade(object me, object victim, object weapon, int damage);
void blood(object me, object victim, object weapon, int damage);
void dust(object me, object victim, object weapon, int damage);
void seven(object me,object victim,object weapon,int damage);
void star(object me, object victim, object  weapon, int damage);
void water(object me, object victim, object weapon, int damage);
void busy(object me,object victim,object weapon,int damage);
void water(object me, object victim, object weapon, int damage);
void temp(object me, object victim ,object weapon, int damage);
mapping *action = ({
// 1
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIG + "】"+NOR + "第一式"+CYN + " o o o《飛千流》\n\n"+HIC + "$N電擊般格掠向前，千百條絢燦明亮的"+HIY + "刀芒"+HIC + "，參差不齊的在同一時間，像炸開了一朵"+HIW + "光球"+HIC + "般朝四週飛射掠舞，這顯然並不單純是些光芒，光芒的後面，還隱鐵著一片魔鬼利會般的刃。還沒有來得及喘息的"+HIM + "$n"+HIC + "目光一眩，已覺得滿天體為金流佈滿" + NOR,

    "dodge"      : 30,
    "parry"      : 20,
    "damage"     : 250,
    "force"      : 400,
    "post_action": (: gold_fluid :),
    "damage_type": "砍傷"
  ]),
//2
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIG + "】"+NOR + "第二式"+GRN + " o o o《血染刃》\n\n"
+HIW + "$N"+HIC + "原地翻身，手腕一抓，$w"+HIC + "已有如怒龍出困般，挾著強猛的功\力筆直射出，倘的右臂同時微彎條揮，$w"+HIC + "「嗡」"+HIC + "的一顫，一把金刀頓時幻映出一個組成輪形的"+HIW + "十三道光芒"+HIC + "，閃射伸縮著暴迎而去！" + NOR,
    "dodge"      : 40,
    "parry"      : 15,
    "damage"     : 280,
    "force"      : 400,
    "post_action": (: light :),
    "damage_type": "破體刀傷"
  ]),
//3
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIG + "】"+NOR + "第三式"+HIB + " o o o《倒奪魂》\n\n"
+HIW + "$N"+HIC + "雙目中煞氣頓現，他在$w"+HIC + "的強烈抖動中，上身驀地偏斜，$w"+HIC + "在斜身之際揚衝而起，卻在刀首指天的剎那，猝然自左臂之下反穿而出，這出刀之勁，又快又狠，迅捷得似一下子追戮上千百年以前流去的時光！" + NOR,

    "dodge"      : 35,
    "parry"      : 20,
    "damage"     : 300,
    "force"      : 400,
    "post_action": (: back_blade :),
    "damage_type": "嚴重刀傷"
  ]),
//4
  ([
    "action"      :
HIG + "\t【"+HIW + "飛流九刀"+HIG + "】"+NOR + "第四式"+HIR + " o o o《網凝紅》\n
"+HIC + "刀刃的飛戮隱映於不規則的"+HIY + "金色網芒"+HIC + "裡，$w"+HIC + "已組合成一片層層重重的寒芒刀山，毫無空檔的包捲土來，有隱隱的風雷之鑿，空氣也在激蕩呼號！驀地"+HIM + "$n"+HIC + "尖號一聲打著轉子摔了出去，滿空的鮮血噴洒如雨！" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 300,
    "force"      : 400,
    "post_action": (: blood :),
    "damage_type": "嚴重砍傷"
  ]),
//5
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIG + "】"+NOR + "第五式"+YEL + " o o o《塵歸土》\n
"+HIW + "$N$w"+HIC + "如電，捲起波波層層的芒彩力迎"+HIM + "$n"+HIC + "，刀芒伸縮不定的協同挾拿，空氣中頓時充滿了刃鋒割掠的銳嘯，$w"+HIC + "所帶出的勁力也似是陡然變得沉重了，頂端的$w"+HIC + "鋒刃卻那麼快捷的切向敵人頸項！" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 300,
    "force"      : 400,
    "post_action": (: dust :),
    "damage_type": "刀傷"
  ]),
//6
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIG + "】"+NOR + "第六式"+HIC + " o o o《星落寂》\n
"+NOR + "$w"+HIC + "伸縮翻飛，快斬狠截，神鬼莫測的瞬息間變幻萬千，在眨眼裡衝舞俯捲，刀影飛閃，像"+HIW + "銀河"+HIC + "的"+HIC + "群星崩落"+HIC + "，$w"+HIC + "密集而狂暴的自四面八方罩下﹗在旋奔之間，"+HIW + "$n"+HIC + "已如星轉般飛旋而去﹗" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 300,
    "force"      : 400,
    "post_action": (: star :),
    "damage_type": "殺傷",
  ]),
//7
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIG + "】"+NOR + "第七式"+HIG + " o o o《七慾滅》\n
"+NOR + "$w"+HIC + "的芒彩奇幻的縱跳飛舞著，一剎東，一剎西，忽而右，忽而左，閃動得有如一個無形的，古怪的"+HIY + "精光"+HIC + "，$N的出手攻拒卻又是那般惊人的準確，幾乎每在招展式現之時都已將"+HIW + "$n"+HIC + "的攻擊與防衛的部位拿捏死了！ " + NOR,

    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 300,
    "force"      : 400,
    "post_action": (: seven :),
    "damage_type": "刀傷",
  ]),
//8
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIW + "】"+NOR + "第八式"+BLU + " o o o《九泉水》\n
"+HIC + "$N右臂倏翻猝揚，只見$w"+HIC + "金芒溜溜，縱橫交織，卻又像極西的電閃，彷彿$N方才出手就已收式，$n似是不敢相信自己的眼睛，寒光突閃，勁風中帶著"+HIG + "「嗆郎郎」"+HIC + "的環震之聲抖出三個圓弧，$N的$w"+HIC + "己"+HIM + "「削」"+HIC + "聲尖嘯，在一片金芒中砍向$n左脅" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 300,
    "force"      : 500,
    "post_action": (: water :),
    "damage_type": "殺傷",
  ]),
//9
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIW + "】"+NOR + "第九式"+HIY + " o o o《金輪測》\n
"+HIC + "只見天地之間"+HIW + "金芒閃爍"+HIC + "，有如千萬個"+HIY + "金球"+HIC + "一起炸裂，又像空中的"+HIR + "烈陽"+HIC + "突然移近了百十倍，豪光萬道，火焰遍野，而風號如嘯，其聲怪異淒怖得足能撕裂人們的腑臟，咻咻的銳氣排空四溢，幾乎成為有形的"+HIB + "流芒o o o o o o\n\n
                         "+HIW + "這便是"+HIC + " 【飛流九刀】"+HIW + "法的精華所聚，一代
                         武中之霸"+HIM + "$N"+HIW + "的終生心血所在亦大半在此\n" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 350,
    "force"      : 500,
    "post_action": (: busy :),
    "damage_type": "刀氣貫穿之傷",
  ]),
//10
  ([
    "action"     :
HIG + "【"+HIW + "飛流九刀"+HIW + "】"+HIC + "\t七式刀意\n"
+HIW + "\t\t\t～"+HIM + "　困　"+HIW + "～　"+HIM + "愁"+HIW + "　～　"+HIM + "城"+HIW + "　～\n\n"
+HIR + "一片浩浩無際的勁氣，彷彿九天之上，綿綿不絕的罡\風，又似瀚海之內，滔滔不盡的波濤，含看無可比擬的巨大力量，向$n捲合而至。" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 400,
    "force"      : 500,
    "post_action": (: temp :),
    "damage_type": "刀氣貫穿之傷",
  ]),
//11
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIW + "】"+HIC + "\t七式刀意\n"
+HIW + "\t\t\t～"+HIB + "　痴　"+HIW + "～　"+HIB + "斷"+HIW + "　～　"+HIB + "腸"+HIW + "　～\n\n"
+HIR + "$N身形已如鬼魅般倏然幌閃起來，舉手投足間，凌厲無匹，一時罡\夙激烈，帶著淒厲的怒嘯，狂猛無倫的襲向$n。" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 450,
    "force"      : 550,
    "post_action": (: temp :),
    "damage_type": "刀氣貫穿之傷",
  ]),
//12
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIW + "】"+HIC + "\t七式刀意\n"
+HIW + "\t\t\t～"+HIC + "　怒　"+HIW + "～　"+HIC + "問"+HIW + "　～　"+HIC + "天"+HIW + "　～\n\n"
+HIR + "$N身形猝然前縱，飛沙旋舞中，一股凌厲無匹的刀氣也怒捲而出！狂猛的勁氣中，$w"+HIR + "如漫天捲雲，在瞬息之間，單向$n全身四周。" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 500,
    "force"      : 600,
    "post_action": (: temp :),
    "damage_type": "刀氣貫穿之傷",
  ]),
//13
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIW + "】"+HIC + "\t七式刀意\n"
+HIW + "\t\t\t～"+HIG + "　橫　"+HIW + "～　"+HIG + "眉"+HIW + "　～　"+HIG + "冷"+HIW + "　～\n\n"
+HIR + "$N刀勢宛如天瀑倒流，又似地泉突湧，上下齊出，攻向$n全身要害重穴。" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 500,
    "force"      : 650,
    "post_action": (: temp :),
    "damage_type": "刀氣貫穿之傷",
  ]),
//14
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIW + "】"+HIC + "\t七式刀意\n"
+HIW + "\t\t\t～"+HIY + "　亂　"+HIW + "～　"+HIY + "情"+HIW + "　～　"+HIY + "斬"+HIW + "　～\n\n"
+HIR + "$N身形如影附形般緊隨而上，傾刻之間，又疾猛無倫的攻出九九八十一刀！更含有一股沉重如山的滔滔勁力，沉重的壓向$n。" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 500,
    "force"      : 700,
    "post_action": (: temp :),
    "damage_type": "刀氣貫穿之傷",
  ]),
//15
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIW + "】"+HIC + "\t七式刀意\n"
+HIW + "\t\t\t～"+HIW + "　傲　"+HIW + "～　"+HIW + "寒"+HIW + "　～　"+HIW + "霜"+HIW + "　～\n\n"
+HIR + "但見青白色的虹光矯如游龍般左右縱橫，刀影漫天而起，凌厲的罡\氣四散瀰合，銀沙飛洒，有如萬點寒星。" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 500,
    "force"      : 750,
    "post_action": (: temp :),
    "damage_type": "刀氣貫穿之傷",
  ]),
//16
  ([
    "action"     :
HIG + "\t【"+HIW + "飛流九刀"+HIW + "】"+HIC + "\t七式刀意\n"
+HIW + "\t\t\t～"+CYN + "　靜　"+HIW + "～　"+CYN + "中"+HIW + "　～　"+CYN + "取"+HIW + "　～\n\n"
+HIR + "$N右手$w"+HIR + "呼聲疾速旋迴，一道渾厚晶瑩的青色光墻，倏而湧起，這青色的透明光墻，亦絲絲迸射著破空勁氣﹗。" + NOR,
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 500,
    "force"      : 800,
    "post_action": (: temp :),
    "damage_type": "刀氣貫穿之傷",
  ]),
});
/*
int valid_learn(object me)
{
  return "不給學!!\n";
}
*/
int valid_enable(string usage)
{
  return ( usage=="blade" || usage=="parry" || usage=="secondary_blade" || usage=="third_blade" );
}

mapping query_action(object me, object weapon)
{
  int skill_level,mf_lv,vf_lv,i;
  object *enemy,victim,wea2;
  string skill,type2;
  if (!me) return;
  weapon = me->query_temp("weapon");
  enemy=me->query_enemy();
  if( !enemy || i=sizeof(enemy) < 1 )
    return action[0]; //抓不到敵人 就讀入action[0] 讓戰鬥環境combatd.c去判斷
  victim = enemy[random(i)];
  wea2 = victim->query_temp("weapon");
  if(wea2)
    if(!(type2=wea2->query("skill_type"))) type2=weapon->query("skill_type");
  skill_level = (int)(me->query_skill("fly-blade",1));
  mf_lv = (int)(me->query_skill("force",1));
  vf_lv = (int)(victim->query_skill("force",1))/2;
  if(random(mf_lv) > random(vf_lv) && me->query_temp("blade_mind") <= 550 && random(10) < 2)
    me->add_temp("blade_mind",random(me->query_skill("blade")/20));
  if( random(mf_lv) > random(vf_lv) && me->query_temp("blade_mind") > 500 && 3>random(8) && me->query_skill("blade") >= 100 && !me->query_temp("moon") && !me->query_temp("imblade") && !me->query_temp("noblade") && !me->query_temp("mind"))
  {
    if(me->query("age") < 40 || me->query_skill("blade",1) < 140 )
    {
      message_vision(HBCYN + "\n\n
$N以意使刀，忽然臻至" + HIY + "【 井 中 月 】" + NOR+HBCYN + "之境，出刀毫無斧鑿之跡，如羚羊掛角，無跡可尋\n\n" + NOR,me,victim);
      me->set_temp("moon",1);
      me->add_temp("blade_mind",-300);
      me->set_temp("busy",1);
      me->improve_skill("blade",random(100));
    }
    else if(me->query("age") < 70 || me->query_skill("blade",1) < 150 )
    {
      message_vision(HBMAG + "\n\n
$N忽然脫離以意使刀" + HIY + "【 井 中 月 】" + NOR+HBMAG + "之境，步入刀人合一，" + HIB + "刀即我，我即刀" + NOR+HBMAG + "，之無上刀境\n\n" + NOR,me,victim);
      me->set_temp("imblade",1);
      me->add_temp("blade_mind",-200);
      me->set_temp("busy",1);
      me->improve_skill("blade",random(200));
    }
    else if(me->query_skill("blade",1) >= 150 && me->query("age") >= 70)
    {
      me->start_busy(2);
      victim->start_busy(3);
      message_vision(HIR + HBWHT + "\n\n
$N終至刀法大成之境，即" + HIC + "【 無 刀 勝 有 刀 】" + NOR+HIR+HBWHT + "之意，無極歸一，臻至刀道至境\n\n" + NOR,me,victim);
      me->set_temp("noblade",1);
      me->add_temp("blade_mind",-100);
      me->set_temp("busy",1);
      me->improve_skill("blade",random(300));
    }
    else
    {
      message_vision(HBGRN + "\n\n
$N雖無法達到" + HIY + "【 井 中 月 】" + NOR+HBGRN + "之境地，但也終也領略到" + HIC + "【飛 流 九 刀】" + NOR+HBGRN + "之些許\刀意\n\n" + NOR,me,victim);
      me->set_temp("mind",1);
      me->add_temp("blade_mind",-400);
    }
  }
  if(me->query_temp("noblade") && me->query_skill("blade",1) > random(450) && !me->query_temp("berserk") && !me->query_temp("conti") && type2 && type2 != "unarmed")
  {
    type2 = wea2->query("skill_type");
    if(!wea2) type2 = "unarmed";
    skill = victim->query_skill_mapped(type2);
    me->set_temp("berserk",1);
    me->set_temp("conti",1);
    message_vision(HIW + "\n\n
$N以刀化" + HIR + "無極" + HIW + "，手中之刀忽隱，招招有如天馬行空般，整個人宛若一" + NOR+HBYEL + "沉獄" + NOR+HIW + "，吸噬著萬物\n
\t     使$n感受到$N似刀非刀，卻又招招遙制於$n，刀使至此\n
\t       $N已至" + HIC + "  破．碎．虛．空  " + HIW + "脫離刀道，而入武道至境\n\n
\t            " + HIY + "《  反 樸 歸 真  萬 流 歸 宗  》 \n\n" + NOR,me,victim);
    weapon->set("ski_type",type2);
    me->set("actions", (: call_other, SKILL_D(skill), "query_action" :));
    for(i=0;i<=random(5)+5;i++)
    {
      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
    me->delete_temp("berserk");
    me->delete_temp("conti");
    weapon->set("ski_type","blade");
    me->reset_action();
    message_vision(HIW + "$N逐漸脫離" + HIC + " 破．碎．虛．空  " + HIW + "之境，回歸刀道\n" + NOR,me,victim);
  }
  if(me->query_temp("busy"))
  {
    return action[random(1)+6];
  }
  if( me->query_temp("moon") || me->query_temp("imblade") || me->query_temp("noblade") || me->query_temp("mind"))
  {
    if(me->query("bellicosity") < 2000)
    {
      if(!me->query_temp("have_call"))
      {
        me->set_temp("have_call",1);
        call_out("deletemind",10,me,victim);
      }
      return action[random(9)+1];
    }
    else if(me->query("bellicosity") < 2500)
    {
      if(!me->query_temp("have_call"))
      {
        me->set_temp("have_call",1);
        call_out("deletemind",10,me,victim);
      }
      return action[random(9)+2];
    }
    else if(me->query("bellicosity") < 3000 || me->query_temp("mind"))
    {
      if(!me->query_temp("have_call"))
      {
        me->set_temp("have_call",1);
        call_out("deletemind",50,me,victim);
      }
      return action[random(9)+3];
    }
    else if(me->query("bellicosity") < 3500 && me->query_temp("moon") || me->query_temp("imblade") || me->query_temp("noblade"))
    {
      if(!me->query_temp("have_call"))
      {
        me->set_temp("have_call",1);
        call_out("deletemind",130,me,victim);
      }
      return action[random(9)+4];
    }
    else if(me->query("bellicosity") < 5000 &&  me->query_temp("imblade") || me->query_temp("noblade"))
    {
      if(!me->query_temp("have_call"))
      {
        me->set_temp("have_call");
        call_out("deletemind",150,me,victim);
      }
      return action[random(9)+5];
    }
    else if(me->query("bellicosity") < 6000 && me->query_temp("noblade"))
    {
      if(!me->query_temp("have_call"))
      {
        me->set_temp("have_call");
        call_out("deletemind",170,me,victim);
     }
      return action[random(9)+6];
    }
    else if(me->query_temp("no_blade"))
    {
      if(!me->query_temp("have_call"))
      {
        me->set_temp("have_call");
        call_out("deletemind",250,me,victim);
      }
      return action[random(9)+7];  
    }
    else if(me->query_temp("mind"))
    {
      if(!me->query_temp("have_call"))
      {
        me->set_temp("have_call",1);
        call_out("deletemind",80,me,victim);
      }
      return action[random(9)+3];
    }
    else if(me->query_temp("moon"))
    {
      if(!me->query_temp("have_call"))
      {
        me->set_temp("have_call",1);
        call_out("deletemind",150,me,victim);
      }
      return action[random(9)+4];
    }
    else if(me->query_temp("imblade"))
    {
      if(!me->query_temp("have_call"))
      {
        me->set_temp("have_call",1);
        call_out("deletemind",180,me,victim);
      }
      return action[random(9)+5];
    }
  }
  else if (skill_level < 10)
    return action[random(2)];
  else if (skill_level < 20 )
    return action[random(3)];
  else if (skill_level < 35 )
    return action[random(4)];
  else if (skill_level < 45 )
    return action[random(5)];
  else if (skill_level < 70 )
    return action[random(6)];
  else if (skill_level < 80 )
    return action[random(7)];
  else if (skill_level < 100 )
    return action[random(8)];
  else
    return action[random(9)];
}

// 刀意消退
int deletemind(object me,object victim)
{
  if (!me || !victim) return;
  me->delete_temp("moon");
  me->delete_temp("imblade");
  me->delete_temp("noblade");
  me->delete_temp("have_call");
  message_vision(RED + "
$N刀意使盡，去式已老，只好收刀回氣再戰。\n" + NOR, me,victim);
  return 1;
}

// 第一招之post_action 傷敵之max_kee
void gold_fluid(object me, object victim, object weapon, int damage)
{
  int my_lv,vi_lv,hurt;
  if (!me || !victim) return;
  weapon=me->query_temp("weapon");
  my_lv=me->query_skill("blade",1)+me->query_skill("fly-blade",1)+me->query("bellicosity")/100;
  vi_lv=victim->query_skill("dodge",1)+victim->query_skill("move",1)+victim->query_cor();
  hurt=me->query_skill("blade",1)*2+me->query_map_skill("dodge",1)*2+me->query_cor()*10+random(me->query("combat_exp")/5000)+me->query_temp("apply/damage");
  if(damage > 0 && my_lv > vi_lv )
  {
    message_vision(YEL + "
$N手中"+weapon->name()+"" + NOR+YEL + "所幻起的黃芒一層層一道道如綿絮般向$n射去\n" + NOR,me,victim);
    victim->receive_wound("kee",hurt,me);
    COMBAT_D->report_status(victim, 1);
  }
}

void light(object me, object victim, object weapon, int damage)
{
  int my_lv,vi_lv,hurt,k,n;
  n=0;
  if (!me || !victim) return;
  weapon=me->query_temp("weapon");
  my_lv=me->query("combat_exp")/100+me->query("bellicosity");
  vi_lv=victim->query("combat_exp")/100+victim->query("bellicosity");
  hurt=me->query_str()+me->query("combat_exp")/10000+damage/10;
  if(damage > 0 && my_lv > vi_lv )
  {
    message_vision(
""+weapon->name()+"" + HIY + "幻出" + HIC + "十三道光芒" + HIY + "從十三個死角閃入$n的體內\n" + NOR,me,victim);
    for(k=0;k<13;k++)
    {
      if(random(my_lv*2) > random(vi_lv))
      {
        victim->receive_woud("kee",hurt,me);
        n++;
      }
    }
    message_vision(HIW + "
$n雖全力擋向十三道刀芒但仍有" + HIY + ""+to_chinese(n)+"" + HIY + "道刀芒" + HIW + "入體，瞬時竄入$n經脈內\n" + NOR,me,victim);
    victim->apply_condition("blade",n);
    COMBAT_D->report_status(victim, 1);
  }
}

void back_blade(object me, object victim, object weapon, int damage)
{
  int my_lv,vi_lv;
  object wea;
  if (!me || !victim) return;
  wea = me->query_temp("secondary_weapon");
  my_lv = me->query_int()+me->query_cor()+me->query_temp("apply/damage")/2;
  vi_lv = victim->query("combat_exp")/50000;
  if(wea && damage > 0 && random(my_lv) > random(vi_lv))
  {
    message_vision(HIB + "
一道刀芒從$N左脅後竄出，$N手中"+wea->name()+"" + NOR+HIB + "在這瞬息之間已疾閃入$n的下腹之中。\n" + NOR,me,victim);
    victim->receive_wound("kee",my_lv+me->query_temp("blade_mind"),me);
    COMBAT_D->report_status(victim, 1);
  }
}

void blood(object me, object victim, object weapon, int damage)
{
  int my_lv,vi_lv,times;
  if (!me || !victim) return;
  my_lv = me->query("max_force")/50+me->query_skill("blade",1)*2+me->query("bellicosity")/10+me->query_skill("force",1)/2;
  vi_lv = victim->query("max_force")/10+victim->query_spi()*10;
  times = me->query_skill("blade",1)/((int)random(victim->query_skill("force")/50)+1);
  if(times > 10 ) times = 10;
  if(victim)
    if( damage > 0 && random(my_lv) > random(vi_lv) && !victim->query_temp("at_blood"))
    {
      victim->add_temp("at_blood",times);
      message_vision(HBRED + "
$N舞出千層刀芒，一波波一層層的向$n湧去，猛列的刀氣直貫入$n體內，直竄往$n心室\n" + NOR,me,victim);
      victim->receive_wound("kee",my_lv/10,me);
      call_out("at_blood",2,me,victim,my_lv/4);
      COMBAT_D->report_status(victim, 1);
  }
}

int at_blood(object me,object victim, int hurt)
{
//靈台 至陽 筋縮 中樞 脊中 懸樞 命門 陽關 腰俞 環跳
  int n;
  string type;
  if (!me || !victim) return;
  n = victim->query_temp("at_blood");
  hurt = hurt - victim->query("max_force")/20;
  if (hurt <= 0) 
  {
    victim->delete_temp("at_blood");
    message_vision(RED + "竄入的刀氣終在$n真氣抵擋下消逝無蹤\n" + NOR,me,victim);
    return 1;
  }
  if(victim->query_temp("at_blood"))
  {
    switch(n)
    {
      case 10:
        type = "環跳穴";
        message_vision(HBRED + "
$n運使真氣抵抗$N的刀氣，但還是讓刀氣衝過" + HIB + ""+type+"" + NOR+HBRED + "直往命門大穴而去\n" + NOR,me,victim);
        victim->receive_wound("kee",hurt,me);
        victim->add("force",-1*hurt);
        victim->add_temp("at_blood",-1);
        COMBAT_D->report_status(victim, 1);
        call_out("at_blood",4,me,victim,hurt);
        break;
      case 9:
        type = "腰俞\穴";
        message_vision(HBRED + "
$n運使真氣抵抗$N的刀氣，但還是讓刀氣衝過" + HIB + ""+type+"" + NOR+HBRED + "直往命門大穴而去\n" + NOR,me,victim);
        victim->receive_wound("kee",hurt,me);
        victim->add("force",-1*hurt);
        victim->add_temp("at_blood",-1);
        COMBAT_D->report_status(victim, 1);
        call_out("at_blood",4,me,victim,hurt);
        break;
      case 8:
        type = "陽關穴";
        message_vision(HBRED + "
$n運使真氣抵抗$N的刀氣，但還是讓刀氣衝過" + HIB + ""+type+"" + NOR+HBRED + "直往命門大穴而去\n" + NOR,me,victim);
        victim->receive_wound("kee",hurt,me);
        victim->add("force",-1*hurt);
        victim->add_temp("at_blood",-1);
        COMBAT_D->report_status(victim, 1);
        call_out("at_blood",4,me,victim,hurt);
        break;
      case 7:
        type = "懸樞穴";
        message_vision(HBRED + "
$n運使真氣抵抗$N的刀氣，但還是讓刀氣衝過" + HIB + ""+type+"" + NOR+HBRED + "直往命門大穴而去\n" + NOR,me,victim);
        victim->receive_wound("kee",hurt,me);
        victim->add("force",-1*hurt);
        victim->add_temp("at_blood",-1);
        COMBAT_D->report_status(victim, 1);
        call_out("at_blood",4,me,victim,hurt);
        break;
      case 6:
        type = "脊中穴";
        message_vision(HBRED + "
$n運使真氣抵抗$N的刀氣，但還是讓刀氣衝過" + HIB + ""+type+"" + NOR+HBRED + "直往命門大穴而去\n" + NOR,me,victim);
        victim->receive_wound("kee",hurt,me);
        victim->add("force",-1*hurt);
        victim->add_temp("at_blood",-1);
        COMBAT_D->report_status(victim, 1);
        call_out("at_blood",4,me,victim,hurt);
        break;
     case 5:
        type = "筋縮穴";
        message_vision(HBRED + "
$n運使真氣抵抗$N的刀氣，但還是讓刀氣衝過" + HIB + ""+type+"" + NOR+HBRED + "直往命門大穴而去\n" + NOR,me,victim);
        victim->receive_wound("kee",hurt,me);
        victim->add("force",-1*hurt);
        victim->add_temp("at_blood",-1);
        COMBAT_D->report_status(victim, 1);
        call_out("at_blood",4,me,victim,hurt);
        break;
     case 4:
        type = "至陽穴";
        message_vision(HBRED + "
$n運使真氣抵抗$N的刀氣，但還是讓刀氣衝過" + HIB + ""+type+"" + NOR+HBRED + "直往命門大穴而去\n" + NOR,me,victim);
        victim->receive_wound("kee",hurt,me);
        victim->add("force",-1*hurt);
        victim->add_temp("at_blood",-1);
        COMBAT_D->report_status(victim, 1);
        call_out("at_blood",4,me,victim,hurt);
        break;
     case 3:
        type = "中樞穴";
        message_vision(HBRED + "
$n運使真氣抵抗$N的刀氣，但還是讓刀氣衝過" + HIB + ""+type+"" + NOR+HBRED + "直往命門大穴而去\n" + NOR,me,victim);
        victim->receive_wound("kee",hurt,me);
        victim->add("force",-1*hurt);
        victim->add_temp("at_blood",-1);
        COMBAT_D->report_status(victim, 1);
        call_out("at_blood",4,me,victim,hurt);
        break;
      case 2:
        type = "靈台穴";
        message_vision(HBRED + "
$n運使真氣抵抗$N的刀氣，但還是讓刀氣衝過" + HIB + ""+type+"" + NOR+HBRED + "直往命門大穴而去\n" + NOR,me,victim);
        victim->receive_wound("kee",hurt,me);
        victim->add("force",-1*hurt);
        victim->add_temp("at_blood",-1);
        COMBAT_D->report_status(victim, 1);
        call_out("at_blood",4,me,victim,hurt);
        break;
      case 1:
        type = "命門穴";
        message_vision(HBRED + "
一股雄渾猛烈的刀氣直竄入$n，使$n心脈一震，生機斷絕\n" + NOR,me,victim);
        victim->add_temp("at_blood",-1);
        COMBAT_D->report_status(victim, 1);
        victim->unconcious();
        break;
    }
  }
  return 1;
}

void dust(object me, object victim, object weapon, int damage)
{
  int my_lv,vi_lv,m,d;
  if (!me || !victim) return;
  weapon = me->query_temp("weapon");
  m=weapon->query("weight")/20;
  d=me->query_temp("apply/damage");
  my_lv = me->query_cps()*2 + me->query_cor()*2 + me->query("combat_exp")/10000;
  vi_lv = victim->query("combat_exp")/10000;
  if(damage > 0 && random(my_lv) > random(vi_lv) )
  {
    message_vision(HBYEL + "
$N受此招刀意所引，"+weapon->name()+"" + NOR+HBYEL + "夾帶著一股沉重的氣息，緩緩使出，深得" + NOR+HBCYN + " 靜、合、取 " + NOR+HBYEL + "之無上刀意\n" + NOR,me,victim);
    victim->receive_wound("kee",m+d+me->query_temp("blade_mind")/2,me);
    victim->apply_condition("blade",10);
    COMBAT_D->report_status(victim, 1);
  }
}

void star(object me, object victim, object weapon, int damage)
{
  int my_lv,vi_lv,force;
  if (!me || !victim) return;
  my_lv = me->query("combat_exp")/10000;
  vi_lv = me->query("combat_exp")/30000;
  force = me->query_temp("blade_mind")/100+1;
  if(damage > 0 && random(my_lv) > random(vi_lv))
  {
    message_vision(HBGRN + "\n
     落   。    星    。    追    。    魂    。    天    。    下    。    寒\n" + NOR,me,victim);
    victim->receive_wound("kee",my_lv*force,me);
    COMBAT_D->report_status(victim, 1);
  }
}

void seven(object me,object victim,object weapon,int damage)
{
  int time,bell,i;
  if (!me || !victim) return;
  bell = (int)me->query("bellicosity")/1000;
  time = (int)me->query("max_force")/1000 + bell;
// 對 time 做限制 以防止連擊數過多 並對高於8 的ppl做保障
  if(time > 8) time = 8+random(3);
    me->delete_temp("busy");
  if( me->query("force_factor") >= 10 && damage > 0)
  {
    if( me->query_temp("berserk") == 0 && me->query("force") > 300)
    {
      me->set_temp("berserk",1);
      message_vision(
HBBLU + "$N手中利刃在一剎那幻成了千百柄，自不同的方向，不同的角度，阻擊著$n的身影。\n" + NOR , me, victim);
      for(i=0;i<=time;i++)
      {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
      }
      me->delete_temp("berserk");
    }
  }
}

void water(object me, object victim, object  weapon, int damage)
{
  int j,bellpower;
  if (!me || !victim) return;
  bellpower = me->query("bellicosity")/40; //  對殺氣的影響做調整
  if(bellpower > 100 ) bellpower = 100;
  if( damage > 0 && me->query("force") > 500 && me->query("bellicosity") > 500)
  {
    message_vision(
HIY + "$N倏起急掠，手中利刃映出金芒千溜，蓬散四射，佈成了一面傘形的金網\n" + NOR , me);
    for(j=1;j<=3;j++)
    {
      message_vision(
HIC + "金芒佈成了一個尺許\方圓的光弧，來勢強勁而急速，待到$n察覺，已身中數刀。\n" + NOR , me, victim);
      victim->receive_wound("kee",bellpower+me->query_temp("blade_mind"),me);
      COMBAT_D->report_status(victim,1);
    }
  }
}

void busy(object me,object victim,object weapon,int damage)
{
//　因為此 skills 只此一定人招 因此不再加 random(2) == 0 來判斷
  if (!me || !victim) return;
  if( damage > 0 && !me->is_busy())
    message_vision(
MAG + "$n 被$N 的刀意所困，正是"+HIG + "【"+HIW + "飛流九刀"+HIW + "】"+MAG + "之無上刀意"+CYN + "『困愁城』\n" + NOR,me,victim);
  me->set_temp("busy",1);
  victim->start_busy(random(3)+1);
  COMBAT_D->report_status(victim);
}

// 懶的再寫 post_action 
void temp(object me, object victim ,object weapon, int damage)
{
  int k;
  if (!me || !victim) return;
  me->add("force",-200);
  weapon = me->query_temp("weapon");
  if(me->query("force") > 500 && damage > 0 && me->query_temp("blade_mind"))
  {
    if(damage <= 200 )
    {
      message_vision(
        HIY + "$N將殺意配合" + HIB + "七式刀意" + HIY + "不斷催鼓內勁，刀刀沉如山嶽，刀芒透出刀身盈有數丈。\n" + NOR,me);
      victim->receive_wound("kee",me->query_temp("blade_mind")*((int)me->query("bellicosity")/3000+1),me);
    }
    else if( damage <= 300 )
    {
      message_vision(
HIC + "$N將體內真氣運諸刀尖，配合" + HIB + "七式刀意" + HIC + "只見刀身霎時渾體通紅，宛若一條" + HIR + "赤龍" + HIC + "翱翔天際。\n" + NOR,me);
      victim->receive_wound("kee",me->query_temp("blade_mind")*(me->query("max_force")/2000+1),me);
      me->add("force",-100);
      me->improve_skill("blade",random(10)+1);
    }
    else if(damage <= 400  && me->query("sen") > 50 && me->query("gin") > 50 && me->query("kee") > 200 && !me->query_temp("berserk"))
    {
      me->set_temp("berserk",1);
      message_vision(
HIW + "$N將全身" + HIG + "精" + HIW + "。" + HIC + "氣" + HIW + "。" + HIY + "神" + HIW + "投入" + HIB + "七式刀意" + HIW + "之無上刀意" + HIW + "宛若" + HIR + "入魔修羅" + HIW + "，暴雨般向$n擊去\n" + NOR,me,victim);
      me->add("sen",-5);
      me->add("gin",-5);
      me->add("kee",-10);
      for(k=0;k<3+random(4);k++)
      {
        message_vision(
HIM + "\n$N將"+weapon->name()+"" + HIM + "斜插於地，就地順勢劃起，一道道邪火由地內冒出\n" + NOR,me);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
      }
      me->delete_temp("berserk");
    }
    else if(damage > 400 && random(10) > 3 && me->query_temp("noblade"))
    {
      message_vision(
HIM + "$N終將" + HIW + "七式刀意" + HIM + "融會貫通，七式合一，使出\n
" + MAG + "。。。。" + HIB + "Ψ" + HIR + "七。意。斬。元    飛。流。破。日" + HIB + "Ψ" + MAG + "。。。。\n
" + HIY + "手中"+weapon->name()+"" + HIY + "一拋，空中挺身轉體，刀鋒劃出一道完美的弧線\n" + NOR,me,victim);
      victim->start_busy(random(2)+1);
      victim->receive_wound("kee",me->query_temp("blade_mind")*(me->query_skill("blade",1)/30),me);
      victim->receive_wound("gin",(int)victim->query("max_gin")/15,me);
      victim->receive_wound("sen",(int)victim->query("max_sen")/15,me);
    }
    else
    {
      message_vision(
        HIY + "$N將殺意配合" + HIB + "七式刀意" + HIY + "不斷催鼓內勁，刀刀沉如山嶽，刀芒透出刀身盈有數丈。\n" + NOR,me);
      victim->receive_wound("kee",me->query_temp("blade_mind")*(me->query("bellicosity")/2000+1),me);
    }
  }
  COMBAT_D->report_status(victim,1);
  if(me->query_skill("fly-blade",1) <= 150 )
  {
    me->improve_skill("blade",random(5)+1);
  }
  else me->improve_skill("blade",random(2)+1);
}

int remove_effect(object me,object victim)
{
  if (!me || !victim) return;
  me->set("force_factor",10);
  message_vision(HIW + "$N刀意使盡，去式已老，只好收刀回氣再戰。\n" + NOR, me);
  return 1;
}

string perform_action_file(string action)
{
  return CLASS_D("ghost")+"/fly-blade/"+action;
}
