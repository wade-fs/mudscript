//============================================================================
//                                    By Falcon
//============================================================================
#include <ansi.h>
#include <combat.h>
#pragma save_binary
inherit SKILL;
inherit SSERVER;

void remove_fdragon(object me);
void remove_berserk(object me);
void ninet(object me,object victim,object weapon,int damage);
void eight(object me,object victim,object weapon,int damage);
mapping *action = ({
//1
([      "action":"
[0m[33m                 [36m▄◣[33m                            [31m◢▆▇▎
[0m[33m           [36m▁▄▇██◣[33m      [31m▂▁          ▁▃[30;41m◤      ◢[37;40m◢　　　　　　[31m◣
[0m[33m   [36m▁▃▅▇██████▇▅▃▁[31m◥▇▆▅▆[41m█        [36;1m◢[34;47m◣[0m▇[31;47m▁[37;40m◣▃▆▇◣[30;41m◤　[31;40m◣
[0m   [30;46m◣[37m  [34;1m▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔[0;36;41m◣[33m  [34;1m▔      ◥[36;47m◤[0;31;47m▁[30m＼＼＼＼＼＼[37;41m▄　[30m▄
[0m     [30;46m◣[37m                                          [36;41m◣[33m    [31;47m◣[30m◢▅▄▅◣　[37;41m◤[30m◢
[0m       [30;46m◣[37m                           [30m▁▃▅▇[40m    [41m◣  ◢[40m             [41m◣  ◢
[0m          [30;46m▅▃▁            ▁▃▅[43m▇[0m\n",
        "parry":                -15,
        "dodge":                -15,
        "force":                500,
        "damage":               200,
        "weapon": HIR + "刀之魔神" + NOR,
        "damage_type":  "割傷",
]),
//2
([      "action":"
[0m[33m                 [36m▄◣[33m                            [31m◢▆▇▎
[0m[33m           [36m▁▄▇██◣[33m      [31m▂▁          ▁▃[30;41m◤      ◢[37;40m◢　　　　　　[31m◣
[0m[33m   [36m▁▃▅▇██████▇▅▃▁[31m◥▇▆▅▆[41m█        [36;1m◢[34;47m◣[0m▇[31;47m▁[37;40m◣▃▆▇◣[30;41m◤　[31;40m◣
[0m   [30;46m◣[37m  [34;1m▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔[0;36;41m◣[33m  [34;1m▔      ◥[36;47m◤[0;31;47m▁[30m＼＼＼＼＼＼[37;41m▄　[30m▄
[0m     [30;46m◣[37m                                          [36;41m◣[33m    [31;47m◣[30m◢▅▄▅◣　[37;41m◤[30m◢
[0m       [30;46m◣[37m                           [30m▁▃▅▇[40m    [41m◣  ◢[40m             [41m◣  ◢
[0m          [30;46m▅▃▁            ▁▃▅[43m▇[0m\n",
        "parry":                -15,
        "dodge":                -15,
        "force":                500,
        "damage":               200,
        "weapon": HIR + "刀之魔神" + NOR,
        "damage_type":  "割傷",
]),
//3
([      "action":"
[0m[33m                 [36m▄◣[33m                            [31m◢▆▇▎
[0m[33m           [36m▁▄▇██◣[33m      [31m▂▁          ▁▃[30;41m◤      ◢[37;40m◢　　　　　　[31m◣
[0m[33m   [36m▁▃▅▇██████▇▅▃▁[31m◥▇▆▅▆[41m█        [36;1m◢[34;47m◣[0m▇[31;47m▁[37;40m◣▃▆▇◣[30;41m◤　[31;40m◣
[0m   [30;46m◣[37m  [34;1m▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔[0;36;41m◣[33m  [34;1m▔      ◥[36;47m◤[0;31;47m▁[30m＼＼＼＼＼＼[37;41m▄　[30m▄
[0m     [30;46m◣[37m                                          [36;41m◣[33m    [31;47m◣[30m◢▅▄▅◣　[37;41m◤[30m◢
[0m       [30;46m◣[37m                           [30m▁▃▅▇[40m    [41m◣  ◢[40m             [41m◣  ◢
[0m          [30;46m▅▃▁            ▁▃▅[43m▇[0m\n",
        "parry":                -15,
        "dodge":                -15,
        "force":                500,
        "damage":               400,
        "weapon": HIR + "刀之魔神" + NOR,
        "damage_type":  "割傷",
]),
//4
([      "action":"
[0m[33m                 [36m▄◣[33m                            [31m◢▆▇▎
[0m[33m           [36m▁▄▇██◣[33m      [31m▂▁          ▁▃[30;41m◤      ◢[37;40m◢　　　　　　[31m◣
[0m[33m   [36m▁▃▅▇██████▇▅▃▁[31m◥▇▆▅▆[41m█        [36;1m◢[34;47m◣[0m▇[31;47m▁[37;40m◣▃▆▇◣[30;41m◤　[31;40m◣
[0m   [30;46m◣[37m  [34;1m▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔[0;36;41m◣[33m  [34;1m▔      ◥[36;47m◤[0;31;47m▁[30m＼＼＼＼＼＼[37;41m▄　[30m▄
[0m     [30;46m◣[37m                                          [36;41m◣[33m    [31;47m◣[30m◢▅▄▅◣　[37;41m◤[30m◢
[0m       [30;46m◣[37m                           [30m▁▃▅▇[40m    [41m◣  ◢[40m             [41m◣  ◢
[0m          [30;46m▅▃▁            ▁▃▅[43m▇[0m\n",
        "parry":                -15,
        "dodge":                -15,
        "force":                500,
        "damage":               300,
        "weapon": HIR + "刀之魔神" + NOR,
        "damage_type":  "割傷",
]),
//5
([      "action":"
[0m[33m                 [36m▄◣[33m                            [31m◢▆▇▎
[0m[33m           [36m▁▄▇██◣[33m      [31m▂▁          ▁▃[30;41m◤      ◢[37;40m◢　　　　　　[31m◣
[0m[33m   [36m▁▃▅▇██████▇▅▃▁[31m◥▇▆▅▆[41m█        [36;1m◢[34;47m◣[0m▇[31;47m▁[37;40m◣▃▆▇◣[30;41m◤　[31;40m◣
[0m   [30;46m◣[37m  [34;1m▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔[0;36;41m◣[33m  [34;1m▔      ◥[36;47m◤[0;31;47m▁[30m＼＼＼＼＼＼[37;41m▄　[30m▄
[0m     [30;46m◣[37m                                          [36;41m◣[33m    [31;47m◣[30m◢▅▄▅◣　[37;41m◤[30m◢
[0m       [30;46m◣[37m                           [30m▁▃▅▇[40m    [41m◣  ◢[40m             [41m◣  ◢
[0m          [30;46m▅▃▁            ▁▃▅[43m▇[0m\n",
        "parry":                -15,
        "dodge":                -15,
        "force":                500,
        "damage":               300,
        "weapon": HIR + "刀之魔神" + NOR,
        "damage_type":  "割傷",
]),
//6
([      "action":"
[0m[33m                 [36m▄◣[33m                            [31m◢▆▇▎
[0m[33m           [36m▁▄▇██◣[33m      [31m▂▁          ▁▃[30;41m◤      ◢[37;40m◢　　　　　　[31m◣
[0m[33m   [36m▁▃▅▇██████▇▅▃▁[31m◥▇▆▅▆[41m█        [36;1m◢[34;47m◣[0m▇[31;47m▁[37;40m◣▃▆▇◣[30;41m◤　[31;40m◣
[0m   [30;46m◣[37m  [34;1m▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔[0;36;41m◣[33m  [34;1m▔      ◥[36;47m◤[0;31;47m▁[30m＼＼＼＼＼＼[37;41m▄　[30m▄
[0m     [30;46m◣[37m                                          [36;41m◣[33m    [31;47m◣[30m◢▅▄▅◣　[37;41m◤[30m◢
[0m       [30;46m◣[37m                           [30m▁▃▅▇[40m    [41m◣  ◢[40m             [41m◣  ◢
[0m          [30;46m▅▃▁            ▁▃▅[43m▇[0m\n",
        "parry":                -15,
        "dodge":                -15,
        "force":                500,
        "damage":               300,
        "weapon": HIR + "刀之魔神" + NOR,
        "damage_type":  "割傷",
]),
//7
([      "action":"
[0m[33m                 [36m▄◣[33m                            [31m◢▆▇▎
[0m[33m           [36m▁▄▇██◣[33m      [31m▂▁          ▁▃[30;41m◤      ◢[37;40m◢　　　　　　[31m◣
[0m[33m   [36m▁▃▅▇██████▇▅▃▁[31m◥▇▆▅▆[41m█        [36;1m◢[34;47m◣[0m▇[31;47m▁[37;40m◣▃▆▇◣[30;41m◤　[31;40m◣
[0m   [30;46m◣[37m  [34;1m▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔[0;36;41m◣[33m  [34;1m▔      ◥[36;47m◤[0;31;47m▁[30m＼＼＼＼＼＼[37;41m▄　[30m▄
[0m     [30;46m◣[37m                                          [36;41m◣[33m    [31;47m◣[30m◢▅▄▅◣　[37;41m◤[30m◢
[0m       [30;46m◣[37m                           [30m▁▃▅▇[40m    [41m◣  ◢[40m             [41m◣  ◢
[0m          [30;46m▅▃▁            ▁▃▅[43m▇[0m\n",
        "dodge":                -15,
        "parry":                -15,
        "force":                500,
        "damage":               300,
        "weapon": HIR + "刀之魔神" + NOR,
        "damage_type":  "割傷",
]),
//8
([      "action":"
[0m[33m                 [36m▄◣[33m                            [31m◢▆▇▎
[0m[33m           [36m▁▄▇██◣[33m      [31m▂▁          ▁▃[30;41m◤      ◢[37;40m◢　　　　　　[31m◣
[0m[33m   [36m▁▃▅▇██████▇▅▃▁[31m◥▇▆▅▆[41m█        [36;1m◢[34;47m◣[0m▇[31;47m▁[37;40m◣▃▆▇◣[30;41m◤　[31;40m◣
[0m   [30;46m◣[37m  [34;1m▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔[0;36;41m◣[33m  [34;1m▔      ◥[36;47m◤[0;31;47m▁[30m＼＼＼＼＼＼[37;41m▄　[30m▄
[0m     [30;46m◣[37m                                          [36;41m◣[33m    [31;47m◣[30m◢▅▄▅◣　[37;41m◤[30m◢
[0m       [30;46m◣[37m                           [30m▁▃▅▇[40m    [41m◣  ◢[40m             [41m◣  ◢
[0m          [30;46m▅▃▁            ▁▃▅[43m▇[0m\n",
        "dodge":                -15,
        "parry":                -15,
        "force":                500,
        "damage":               300,
        "post_action":          (: ninet :),
        "weapon": HIR + "刀之魔神" + NOR,
        "damage_type":  "割傷",
]),
//9
([      "action":"
[0m[33m                 [36m▄◣[33m                            [31m◢▆▇▎
[0m[33m           [36m▁▄▇██◣[33m      [31m▂▁          ▁▃[30;41m◤      ◢[37;40m◢　　　　　　[31m◣
[0m[33m   [36m▁▃▅▇██████▇▅▃▁[31m◥▇▆▅▆[41m█        [36;1m◢[34;47m◣[0m▇[31;47m▁[37;40m◣▃▆▇◣[30;41m◤　[31;40m◣
[0m   [30;46m◣[37m  [34;1m▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔[0;36;41m◣[33m  [34;1m▔      ◥[36;47m◤[0;31;47m▁[30m＼＼＼＼＼＼[37;41m▄　[30m▄
[0m     [30;46m◣[37m                                          [36;41m◣[33m    [31;47m◣[30m◢▅▄▅◣　[37;41m◤[30m◢
[0m       [30;46m◣[37m                           [30m▁▃▅▇[40m    [41m◣  ◢[40m             [41m◣  ◢
[0m          [30;46m▅▃▁            ▁▃▅[43m▇[0m\n",
        "dodge":                -15,
        "parry":                -15,
        "force":                500,
        "damage":               300,
        "post_action":          (: eight :),
        "weapon": HIR + "刀之魔神" + NOR,
        "damage_type":  "割傷",
]),
});
mapping query_action(object me,object weapon)
{
  object *enemy,victim,weaa,weap;
  int me_exp,en_exp,h,i,j,time,damage;
  int killdragon = (int)me->query_temp("dragon/power");
  int firedragon = (int)me->query_function("firedragon",1);
  weap = me->query_temp("weapon");
  weaa = me->query_temp("secondary_weapon");
  enemy = me->query_enemy();
  h = sizeof(enemy);
  victim = enemy[random(h)];
  me_exp = me->query("combat_exp",1);
  en_exp = victim->query("combat_exp",1);
  time = me_exp/1000000+(me->query_cps()+me->query_cor())/20;
  time = random(time);
 
  if(!me->query_temp("dragon/kill") && victim && me_exp>=3000000 && !me->query_temp("dragon/power") )
 {
  	me->add_temp("dragon/kill",1);        
  	me->add_temp("dragon/power",firedragon/10);
  	call_out("remove_fdragon",5+me->query_temp("dragon/power"),me);
 }

  if(me->query_temp("dragon/power"))
 {
  	int dmg_rate;        
  	dmg_rate = 15-killdragon < 2 ? 2 : 15-killdragon; 
 	message_vision("\n",me);
	message_vision(NOR + "[0m[33;1m                   ╔╗                                    ╔╗\n" + NOR,me);
	message_vision(NOR + "[0m[33;1m                   ╚╬══════════════════╬╝\n" + NOR,me);
	message_vision(NOR + "[0m                     [33;1m║[41m         冰火五重‧誅天現世         [40m║\n" + NOR,me);
	message_vision(NOR + "[0m[33;1m                   ╔╬══════════════════╬╗\n" + NOR,me);
	message_vision(NOR + "[0m[33;1m                   ╚╝                                    ╚╝[0m\n" + NOR,me);
  	victim->receive_damage("gin",me->query("max_gin")/(dmg_rate));
  	victim->receive_damage("kee",me->query("max_kee")/(dmg_rate));
  	victim->receive_damage("sen",me->query("max_sen")/(dmg_rate));
  	victim->start_busy(1);
  	if( me->query_temp("dragon/power")==1 && random(5)==0 )
       {
  	me->receive_damage("gin",me->query("max_gin")/(dmg_rate));
  	me->receive_damage("kee",me->query("max_kee")/(dmg_rate));
  	me->receive_damage("sen",me->query("max_sen")/(dmg_rate));
  	me->start_busy(1);
       }
  	me->add_temp("dragon/power",-1);
 }
  if(!me->query_temp("berserk_on") && random(me_exp)>random(en_exp))
 {
  	call_out("remove_berserk",10,me);        
	for(i=0;i<time;i++)
       {
  	me->set_temp("berserk_on",1);
  	COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_QUICK);
       }
 }
  return action[random(sizeof(action))];
}

void remove_fdragon(object me)
{
 message_vision(BRED+HIY + "\n【$N的冰火五重天所形成的火燄及冰燄逐漸的消失了】\n" + NOR,me);
 me->delete_temp("dragon/kill");   
}

void remove_berserk(object me)
{
 this_player()->delete_temp("berserk_on");
}

 void ninet(object me,object victim,object weapon,int damage)
{
 int i;
 message_vision(NOR + "[0m[33;1m                   ╔╗                                    ╔╗\n" + NOR,me);
 message_vision(NOR + "[0m[33;1m                   ╚╬══════════════════╬╝\n" + NOR,me);
 message_vision(NOR + "[0m                     [33;1m║[41m         葵水神雷‧雷動九天         [40m║\n" + NOR,me);
 message_vision(NOR + "[0m[33;1m                   ╔╬══════════════════╬╗\n" + NOR,me);
 message_vision(NOR + "[0m[33;1m                   ╚╝                                    ╚╝[0m\n" + NOR,me);
 for(i = 0;i < 9; i++)
{               
  message_vision(sprintf(HIC + "
◥▓◣        ◣                            " + HIY + "$N的拳影如雷電般的快速，" + HIC + "
    ◥▓◣    ◥▓◣              " + HIY + "一片雷氣縱橫，頓時雷電交錯，四周霎時天崩地裂。" + HIC + "
        ◥▓◣    ◥▓◣          " + HIY + "只見數到雷勁破天而去，發出一道道強大的閃光，在" + HIC + "
            ◥▓◣  ◢▓◣        " + HIY + "方圓十里之內形成一個強大的氣流，只見天空落下一" + HIC + "
                ◥▓◤  ◥▓◣    " + HIY + "道道的閃電，即隨著無疇雷電展開猛烈攻擊。。。。" + HIC + "
                            ◥▓◣ 『" + HIB + "葵‧水‧神‧雷" + HIC + "』" + HIY + "─終式─" + HIC + "「" + HIR + "雷‧動‧九‧天" + HIC + "」\n" + NOR),me);
 victim->receive_damage("kee",2000);
 COMBAT_D->report_status(victim);
}                	
}

 void eight(object me,object victim,object weapon,int damage)
{
 int base, dam, level, power, limit, mks, bell, i, j;
 base = me->query_skill("unarmed",1);
 mks = (int)(me->query("MKS")/1000);
 bell = (int)(me->query("bellicosity")/2000) + 1;
 dam = base + mks + random((int)bell);
 power = (int)(me->query("max_force")/1000) + 1;
 limit = (int)(dam*power);
 level = bell;
 if(level > 8) level = 8;
 if( me->query("combat_exp") > 8000000 )
{ if(!victim){return;}
 message_vision(NOR + "
" + HIB + "    ╭═╯ ╰═╮     ═╦═╭╦═══       ══╬══       ═══╦═══
" + HIC + "    ║         ║     ╭╯╮  ╰═╮═╮     ╰═╬═╯     ╭═══╬═══╮
" + HIB + "  ╭╯         ╰╮   ║  ║╭═╮║║║ ══╬═╬═╬══ ║╰╩╮║╰╩╮║
" + HIC + "  ║             ║   ╰╭╯║  ║║╭╯ ╠═╬╣║╠╬═╣ ╯╭══╦══╮╰
" + HIB + "  ║             ║   ╭║  ╰═╯╠╯╰ ╰═╬╯  ╰╬═╯   ╠══╬══╣
" + HIC + "  ╯             ╰   ╰╯  ═══╩═╯ ══╬═  ═╬══   ╰══╩══╯
\n" + NOR,me,victim);
 for(i=0;i<=level;i++)
{
 switch(random(8))
{
 case 0:
 if(!victim){return;}
 message_vision(HIR + "
          ☆                ★
            ●=●=●=●=█◣  
            ████████" + HIC + "                            狂－－－雷" + HIR + "
            ▓▓▓▓▓▓██" + HIC + "                            ｜　　　｜" + HIR + "
            ▓▓▓▓▓▓◥█" + HIC + "                            驟－－－降" + HIR + "
                  ◥███◤  
          ★                ☆\n" + NOR,me,victim);
 break;
 break;
 case 1:
 if(!victim){return;}
 message_vision(HIY + "
                                                  ★                ☆
                                                    ◢█=●=●=●=●      
                " + HIC + "雷－－－網" + HIY + "                          ████████      
                " + HIC + "｜　　　｜" + HIY + "                          ██▓▓▓▓▓▓      
                " + HIC + "森－－－羅" + HIY + "                          █◤▓▓▓▓▓▓      
                                                    ◥███◤
                                                  ☆               ★\n" + NOR,me,victim);
 break;
 break;
 case 2:
 if(!victim){return;}
 message_vision(HIR + "
          ☆                ★
            ●=●=●=●=█◣  
            ████████" + HIC + "                            八－－－方" + HIR + "
            ▓▓▓▓▓▓██" + HIC + "                            ｜　　　｜" + HIR + "
            ▓▓▓▓▓▓◥█" + HIC + "                            暴－－－雷" + HIR + "
                  ◥███◤  
          ★                ☆\n" + NOR,me,victim);
 break;
 break;
 case 3:
 if(!victim){return;}
 message_vision(HIY + "
                                                  ★                ☆
                                                    ◢█=●=●=●=●      
                " + HIC + "雷－－－霆" + HIY + "                          ████████      
                " + HIC + "｜　　　｜" + HIY + "                          ██▓▓▓▓▓▓      
                " + HIC + "風－－－暴" + HIY + "                          █◤▓▓▓▓▓▓      
                                                    ◥███◤
                                                  ☆               ★\n" + NOR,me,victim);
 break;
 break;
 case 4:
 if(!victim){return;}
 message_vision(HIR + "
          ☆                ★
            ●=●=●=●=█◣  
            ████████" + HIC + "                            雷－－－霆" + HIR + "
            ▓▓▓▓▓▓██" + HIC + "                            ｜　　　｜" + HIR + "
            ▓▓▓▓▓▓◥█" + HIC + "                            萬－－－均" + HIR + "
                  ◥███◤  
          ★                ☆\n" + NOR,me,victim);
 break;
 break;
 case 5:
 if(!victim){return;}
 message_vision(HIY + "
                                                  ★                ☆
                                                    ◢█=●=●=●=●      
                " + HIC + "雷－－－霆" + HIY + "                          ████████      
                " + HIC + "｜　　　｜" + HIY + "                          ██▓▓▓▓▓▓      
                " + HIC + "縱－－－橫" + HIY + "                          █◤▓▓▓▓▓▓      
                                                    ◥███◤
                                                  ☆               ★\n" + NOR,me,victim);
 break;
 break;
 case 6:
 if(!victim){return;}
 message_vision(HIR + "
          ☆                ★
            ●=●=●=●=█◣  
            ████████" + HIC + "                            潛－－－雷" + HIR + "
            ▓▓▓▓▓▓██" + HIC + "                            ｜　　　｜" + HIR + "
            ▓▓▓▓▓▓◥█" + HIC + "                            轟－－－天" + HIR + "
                  ◥███◤  
          ★                ☆\n" + NOR,me,victim);
 break;
 break;
 case 7:
 if(!victim){return;}
 message_vision(HIY + "
                                                  ★                ☆
                                                    ◢█=●=●=●=●      
                " + HIC + "轟－－－雷" + HIY + "                          ████████      
                " + HIC + "｜　　　｜" + HIY + "                          ██▓▓▓▓▓▓      
                " + HIC + "戰－－－野" + HIY + "                          █◤▓▓▓▓▓▓      
                                                    ◥███◤
                                                  ☆               ★\n" + NOR,me,victim);
 break;
 break;
}
 for(j=0;j<=2;j++)
{  if(!victim){return;}
 victim->receive_wound("kee",limit);
 COMBAT_D->report_status(victim);
}
}
}
}
 //============================================================================
 //這裡說明你所能使用在那個基本的 Skill 上面, 也就是所謂的 Enable.
 //============================================================================
 int valid_enable(string usage)
{
 return (usage=="unarmed")||(usage=="blade");
}
 //============================================================================
 //這裡說明你所能使用的 Perfrom 在哪個 Class 的目錄之下.  若內功是用 exert 發出
 //的功能則必需加入下面幾行做為判斷 exert 的導入. 我們假設這個 Skill 為內功用途
 //得到下面的寫法..
 // string exert_function_file(string func)
 //{
 // return CLASS_D("darker")+"/kill-dragon/"+func;
 //}
 //============================================================================
 // string perform_action_file(string action)
 //{
 // return CLASS_D("darker")+"/kill-dragon/"+action;
 //}



