// 大慈大悲掌  by CHAD

#include <combat.h>
#include <ansi.h>

inherit SKILL;
inherit SSERVER;

void hurt(object me,object victim, object weapon, int damage);//普通攻擊副攻
void killair(object me,object victim,object weapon,int damage);//吸殺氣副攻
void buddha(object me,object victim,object weapon,int damage);//光明佛法副攻
void addkee(object me,object victim,object weapon,int damage);//補血副攻
void condi(object me,object victim,object weapon,int damage);//附加狀態副攻
void hartt(object me,object victim,object weapon,int damage);//內傷副攻
void bz	(object me,object victim,object weapon,int damage);//機率busy副攻
void happy(object me,object victim,object weapon,int damage);//慈悲喜樂連擊副攻
void buddha2(object me,object victim,object weapon,int damage);//打魔教魔刀副攻.
void sohurt(object me,object victim,object weapon,int damage);//超痛攻擊副攻

mapping *action = ({
	//0 我佛慈悲
  ([ "action" : "只見$N雙手合十,站在原地,口中念念有詞,看來這就是" + HIW + "大慈大悲掌之" + HIG + "『" + HIY + "我佛慈悲" + HIG + "』" + NOR + ",掌掌往$n各處拍去." + NOR,
    "dodge"      :   -30,
    "parry"      :   -20,
    "damage"     :    50,
    "force"      :    50,
    "damage_type":   "瘀傷",
    "post_action": (: call_other,__FILE__,"hurt" :),
  ]),
  //1 我佛慈悲
  ([ "action" : "只見$N雙手合十,站在原地,口中念念有詞,看來這就是" + HIW + "大慈大悲掌之" + HIG + "『" + HIY + "我佛慈悲" + HIG + "』" + NOR + ",掌掌往$n各處拍去." + NOR,
    "dodge"      :   -30,
    "parry"      :   -20,
    "damage"     :    50,
    "force"      :    50,
    "damage_type":   "瘀傷",
    "post_action": (: call_other,__FILE__,"hurt" :),
  ]),
  //2 慈悲如懷
  ([ "action" : "此時只見$N馬步一蹲,左手握拳於腰間,右手一鼓掌力往前發出,原是" + HIW + "大慈大悲掌之" + HIG + "『" + HIY + "慈悲如懷" + HIG + "』" + NOR + ",一股柔和掌力往$n前方打去,看來軟弱的掌力卻讓$n身受內傷." + NOR,
    "dodge"      :    -30,
    "parry"      :    -20,
    "damage"     :     60,
    "force"      :     60,
    "damage_type":   "瘀傷",
  ]),
  //3 苦若悲涅
  ([ "action" : "$N身形微閃,繞至$n身後使出" + HIW + "大慈大悲掌之" + HIG + "『" + HIY + "苦若悲涅" + HIG + "』" + NOR + ",$n身重此掌,突然雙腿一軟,當場跪了下來." + NOR,
    "dodge"      :   -40,
    "parry"      :   -30,
    "damage"     :    80,
    "force"      :    80,
    "damage_type":   "瘀傷",
  ]),
  //4 曼殊琉璃手           
  ([ "action" : "$N手捻蓮花,在掌起掌落之間,只見萬物絡動,看來此乃" + HIW + "大慈大悲掌之" + HIG + "『" + HIY + "曼殊琉璃手" + HIG + "』" + NOR + ",$n$l受到此掌餘力,全身關節喀喀作響." + NOR,
    "dodge"      :   -40,
    "parry"      :   -30,
    "damage"     :    90,
    "force"      :    90,
    "damage_type":   "瘀傷",
  ]),
  //5 無極上佛            
  ([ "action" : "只見$N一躍至空中,隨即盤腿以打坐方式直坐至地,使出" + HIW + "大慈大悲掌之" + HIG + "『" + HIC + "無極上佛" + HIG + "』" + NOR + ",背後閃閃金光使$n眼睛難以張見,在此瞬間已受到光明佛法之傷." + NOR,
    "dodge"      :   -50,
    "parry"      :   -40,
    "damage"     :    100,
    "force"      :    100,
    "damage_type":   "瘀傷",
    "post_action": (: call_other,__FILE__,"buddha" :),
  ]),
  //6 密多若心經            
  ([ "action" : "$N口中念著:南無阿彌陀密果若多,此為" + HIW + "大慈大悲掌之活血絡氣" + HIG + "『" + HIR + "密多若心經" + HIG + "』" + NOR + ",只見$N傷勢已好了大半." + NOR,
    "dodge"      :   -50,
    "parry"      :   -40,
    "damage"     :    120,
    "force"      :    120,
    "damage_type":   "瘀傷",
    "post_action": (: call_other,__FILE__,"addkee" :),
  ]),
  //7 藥沐禮佛槃            
  ([ "action" : "涅盤三世,輪迴依舊." + HIW + "大慈大悲掌之" + HIG + "『" + HIY + "藥沐禮佛槃" + HIG + "』" + NOR + "掌力一出,只見$n$l受了重傷,無病之人受此禮佛之禮,自身當招架不住." + NOR,
    "dodge"      :   -50,
    "parry"      :   -50,
    "damage"     :    130,
    "force"      :    130,
    "damage_type":   "瘀傷",
    "post_action": (: call_other,__FILE__,"condi" :),
  ]),
  //8 無量壽            
  ([ "action" : "$N雙手做" + HIC + "海納千川" + NOR + "之勢,使出" + HIW + "大慈大悲掌之" + HIG + "『" + HIM + "無量壽" + HIG + "』" + NOR + ",$n感受到無比的壓力往$l施加上來,看來已造成嚴重內傷." + NOR,
    "dodge"      :   -60,
    "parry"      :   -60,
    "damage"     :    150,
    "force"      :    150,
    "damage_type":   "瘀傷",
    "post_action": (: call_other,__FILE__,"hartt" :),
  ]),
  //9 苦海無涯            
  ([ "action" : "" + HIW + "大慈大悲掌" + HIG + "『" + HIB + "苦海無涯" + HIG + "』" + NOR + "一使出,你彷彿進入無為境界,靈魂進入十八層地獄,看見地獄慘狀你不禁心頭一驚,當你回神之時已經嚇的無法招架." + NOR,
    "dodge"      :   -60,
    "parry"      :   -60,
    "damage"     :    160,
    "force"      :    160,
    "damage_type":   "瘀傷",
  ]),
  //10 佛剎極微塵            
  ([ "action" : "$N突然一個翻身,而後將雙掌往地面打去.只見地面表層微裂,此為" + HIW + "大慈大悲掌" + NOR + "威力極強之" + HIG + "『佛剎極微塵" + HIG + "』" + NOR + ",只見飛砂走石,四處草木皆兵,看來$N是動了殺招!" + NOR,
    "dodge"      :   -60,
    "parry"      :   -60,
    "damage"     :    200,
    "force"      :    200,
    "damage_type":   "瘀傷",
  ]),
  //11 入來般若懺            
  ([ "action" : "$N突然沉靜了下來,四周的節奏似乎全部慢了下來,原來此招為" + HIW + "大慈大悲掌之" + HIG + "『" + HIW + "入來般若懺" + HIG + "』" + NOR + ",禮佛之聲穿入$n的耳中,頓時$n的殺戮之氣降低了許\多." + NOR,
    "dodge"      :   -70,
    "parry"      :   -70,
    "damage"     :    220,
    "force"      :    220,
    "damage_type":   "瘀傷",
    "post_action": (: call_other,__FILE__,"killair" :),
  ]),
  //12 法護蓮華            
  ([ "action" : "$N使出" + HIW + "大慈大悲掌奧義-" + HIG + "『" + HIC + "法護蓮華" + HIG + "』" + NOR + ",只見$N身邊慢慢浮現出許\多蓮花的影像,圍繞在$N身旁,$N突然一個箭步,$n已經被此景包圍,動彈不得." + NOR,
    "dodge"      :   -80,
    "parry"      :   -80,
    "damage"     :    250,
    "force"      :    250,
    "damage_type":   "瘀傷",
    "post_action": (: call_other,__FILE__,"bz" :),
  ]),
  //13 世尊念諸            
  ([ "action" : "$N使出" + HIW + "大慈大悲掌奧義-" + HIG + "『" + HIY + "世尊念諸" + HIG + "』" + NOR + ",佛法弘揚,道佛天擊,佛經朗誦之聲直傳入耳,$n修行不夠,只見$n承受不住快要暈去." + NOR,
    "dodge"      :   -80,
    "parry"      :   -80,
    "damage"     :    250,
    "force"      :    250,
    "damage_type":   "瘀傷",
  ]),
  //14 慈悲喜樂終無時            
  ([ "action" : "$N使出" + HIW + "大慈大悲掌奧義-" + HIG + "『" + HIR + "慈悲喜樂終無時" + HIG + "』" + NOR + ",只見$N掌風越舞越快,彷彿$N已經歷過人生百態,已經進入無明、無想、無視的境界,只見$N雄厚有勁的掌力往$n的$l一再攻去." + NOR,
    "dodge"      :   -90,
    "parry"      :   -90,
    "damage"     :    250,
    "force"      :    250,
    "damage_type":   "瘀傷",
    "post_action": (: call_other,__FILE__,"happy" :),
  ]),
  //15 降諸魔道            
  ([ "action" : "菩提情,慈悲心." + HIW + "大慈大悲掌之不傳奧義-" + HIG + "『" + HIB + "降諸魔道" + HIG + "』" + NOR + ",$N逼出全身內力,誓言要將全數魔道全數收服!!" + NOR,
    "dodge"      :   -100,
    "parry"      :   -100,
    "damage"     :    280,
    "force"      :    280,
    "damage_type":   "瘀傷",
    "post_action": (: call_other,__FILE__,"buddha2" :),
  ]),
  //16 六根淨念            
  ([ "action" : "" + HIW + "大慈大悲掌最終式-" + HIG + "『" + HIW + "六根淨念" + HIG + "』" + NOR + ",$N似進入無為境界,雙手合掌站在原處.當你正摸不著頭緒時,七孔突然爆出大量血來,前後一刻鐘不到居然已經身負重傷!!" + NOR,
    "dodge"      :   -120,
    "parry"      :   -120,
    "damage"     :    350,
    "force"      :    350,
    "damage_type":   "瘀傷",
    "post_action": (: call_other,__FILE__,"sohurt" :),
  ]),


  //17 非少林弟子
  ([ "action" : HIW + "非少林弟子." + NOR,
    "dodge"      :   -30,
    "parry"      :   -20,
    "damage"     :    70,
    "force"      :    70,
    "damage_type":   "想幹麻",
  ]),
});

mapping query_action(object me,object weapon)
{
    int i,j,k,sklevel,limit;
    object obj = offensive_target(me);
    sklevel = me->query_skill("seventy-two",1);
    limit = sklevel/10;
    i=me->query("combat_exp",1)/1000000;
    j=me->query("bonzez");
    k=random(10);
    
    if(!j) j=0;
    if(me->query("class")!="bonze"){return action[17];}
    
    if(limit<3){return action[random(3)];}
    else if(limit<4){return action[random(4)];}
    else if(limit<5){return action[random(5)];}
    else if(limit<6){return action[random(6)];}
    else if(limit<7){return action[random(6)+1];}
    else if(limit<8){return action[random(6)+2];}
    else if(limit<9){return action[random(7)+1];}
    else if(limit<10){return action[random(7)+2];}
    else {
    	if(j==1){
    	 if(i>=10){
    		if(k>5){return action[15];}
    		else{return action[random(10)+5];}
    		}else{return action[random(6)+6];}
    	}else{return action[random(12)];}
   }
}

void hurt(object me,object victim, object weapon, int damage)//普通攻擊副攻
{
	int i;
}

void killair(object me,object victim,object weapon,int damage)//吸殺氣副攻
{
}
 
void buddha(object me,object victim,object weapon,int damage)//光明佛法副攻
{
}
 
void addkee(object me,object victim,object weapon,int damage)//補血副攻
{
}
 
void condi(object me,object victim,object weapon,int damage)//附加狀態副攻
{
}
 
void hartt(object me,object victim,object weapon,int damage)//內傷副攻
{
}
 
void bz	(object me,object victim,object weapon,int damage)//機率busy副攻
{
}
 
void happy(object me,object victim,object weapon,int damage)//慈悲喜樂連擊副攻
{
	int i,j,kar;
	kar = me->query_kar()/5;
	j=random(kar);
	if(me->query("bonze/berserk")){
	for (i=0;i<j;i++){
		message_vision(HIC + "$N領悟了慈悲喜樂的連擊招式,源源不絕的始將出來!!\n" + NOR,me);
		COMBAT_D->do_attack(me,victim , weapon, TYPE_QUICK);
		sprintf("%d",victim->query("kee"));
	}
}
}
 
void buddha2(object me,object victim,object weapon,int damage)//打魔教魔刀副攻.
{
}
 
void sohurt(object me,object victim,object weapon,int damage)//超痛攻擊副攻
{
}
 

int valid_enable(string usage) 
{
    return (usage=="unarmed");
}
int valid_learn(object me)
{
	me = this_player();
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("大慈大悲掌是掌法..必須放下兵刃。\n");
    return 1;
}
int practice_skill(object me)
{
    return 1;
}
