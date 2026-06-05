//tunsword 迅雷劍 by roger
//需學過迅雷劍法才可施展 ( set("quest/tunder_sword",1) )
//需解謎,解謎過程中魔王exp 300萬,so 強點亦無妨
//需 en sword none so 攻防將大幅下降,所以攻擊力調高
// weapon上限為80因為特殊武器特准為115
// QC by Anmy 3/3/98
#include <weapon.h>
#include <ansi.h>

inherit SWORD;


string *parry_msg=({
        HIC + "$n以快制快,敵快$n更快,瞬間織成一道劍網將敵招盡數盪開!\n" + NOR,
        
        HIC + "$n且戰且走,一連串的兵器撞擊聲後,$n已將$N的快招全部化解!\n" + NOR,
        });

mapping *action = ({
([ "action" : HIW + "$N使出迅雷劍法第一式" + HIB + "『風捲殘雲』" + HIW + ",手中的$w" + HIW + "快速舞動著,挾著陣陣風雷襲向四周,一時間劍氣縱橫" + NOR,
        "dodge":   -20,
        "parry":   -20,
        "damage":   80,
        "force":    50,
        "damage_type" : "刺傷",
]),

([ "action" : HIW + "$N手中$w" + HIW + "突然嗡嗡巨響,使出迅雷劍法第二式" + HIB + "『空谷雷鳴』" + HIW + ",手中$w" + HIW + "發出霹靂巨響刺向四周的敵人 " + NOR,
        "dodge":    40,
        "parry":    80,
        "damage":   80,
        "force":    50,
        "damage_type" : "刺傷",
]),

([ "action" :HIW + "$N手中$w" + HIW + "急速顫動,瞬間滿天劍花閃閃,正是迅雷劍法第三式" + HIB + "『落英繽紛』" + HIW + ",招如其名,只見敵人的血如落花般飛濺..." + NOR,
        "dodge":    40,
        "parry":    80,
        "damage":   80,
        "force":    50,
        "damage_type" : "刺傷",
]),

([ "action" : HIW + "$N身形急旋,使出迅雷劍法第四式" + HIB + "『秋風掃葉式』" + HIW + ",只見四周捲起滾滾塵沙,令人摸不清$N在何方..." + NOR,
        "dodge":     40,
        "parry":    80,
        "damage":   80,
        "force":    50,
        "damage_type" : "砍傷",
]),

([ "action" : HIW + "$N手捏劍訣,忽然手中的$w" + HIW + "往天空飛去,瞬時間數道劍氣往下激射,正是迅雷劍法第五式" + HIB + "『白虹弳天』" + NOR,
        "dodge":   40,
        "parry":   80,
        "damage":   80,
        "force":    50,
        "damage_type" : "割傷",
]),

([ "action" : HIW + "$N使出迅雷劍法第六式" + HIB + "『昇龍旋』" + HIW + "身形猶如一條灰龍急旋而上,且散發出凜冽的氣息襲向四周,好像要一舉吞沒敵人似的" + NOR,
        "dodge":   40,
        "parry":   80,
        "damage":   80,
        "force":    50,
        "damage_type" : "割傷",
]),

([ "action" : HIW + "$N大喝一聲,使出迅雷劍法第七式" + HIB + "『點落七星』" + HIW + ",一瞬間已向四周刺出了七七四十九劍!" + NOR,
        "dodge":   45,
        "parry":   80,
        "damage":   80,
        "force":    50,
        "damage_type" : "刺傷",
]),

([ "action" : HIW + "$N手中的$w" + HIW + "忽劈忽刺,一招迅雷劍法第八式" + HIB + "『雷電交作』" + HIW + "使將出來,四周響起了隆\隆\巨\響\!" + NOR,
        "dodge":   40,
        "parry":   80,
        "damage":   80,
        "force":    50,
        "damage_type" : "砍傷",
]),

([ "action" : HIW + "$N手中的$w" + HIW + "劍芒忽然一長,使出迅雷劍法第九式" + HIB + "『疾風暴雨』" + HIW + ",只見劍芒不停的吞吐閃爍,令人眼花撩亂間$w" + HIW + "已穿體而出..." + NOR,
        "dodge":   40,
        "parry":   80,
        "damage":   80,
        "force":    50,
        "damage_type" : "穿體之傷",
]),

([ "action" : HIW + "$N使出絕頂輕功,一招迅雷劍法第十式" + HIB + "『雷厲風行』" + HIW + "使將出來,周圍敵人紛紛不住地倒退..." + NOR,
        "dodge":   80,
        "parry":   80,
        "damage":   80,
        "force":    50,
        "damage_type" : "砍傷",
]),

([ "action" : HIW + "$N身形一晃,手中$w" + HIW + "不絕的向敵人追隨而去,正是迅雷劍法第十一式" + HIB + "『如影隨形』" + HIW + "令敵人避無可避" + NOR,
        "dodge":   40,
        "parry":   80,
        "damage":   80,
        "force":    50,
        "damage_type" : "刺傷",
]),

([ "action" : HIW + "$N手中的$w" + HIW + "忽然變成軟軟綿綿,劍招去勢詭異莫測,正是迅雷劍法第十二式" + HIB + "『繞指柔劍』" + HIW + "令敵人無從招架起" + NOR,
        "dodge":   40,
        "parry":   80,
        "damage":   80,
        "force":    50,
        "damage_type" : "割傷",
]),

([ "action" : HIW + "$N手中的$w" + HIW + "飛射而出,使出迅雷劍法第十三式" + HIB + "『御劍成風』" + HIW + "只見$w" + HIW + "在$N雙手真氣的控制下以極高的速度刺向周圍的敵人。" + NOR,
        "dodge":   40,
        "parry":   80,
        "damage":   80,
        "force":    50,
        "damage_type" : "刺傷",
]),

([ "action" : HIW + "$N使出迅雷劍法第十四式" + HIB + "『幻劍式』" + HIW + ",手中的$w" + HIW + "忽然飛快的舞動,形成一道道幻影刺向周圍的敵人。" + NOR,
        "dodge":   40,
        "parry":   80,
        "damage":   80,
        "force":    50,
        "damage_type" : "刺傷",
]),

([ "action" : HIW + "$N手中的$w" + HIW + "往外一分,忽然化成成千上萬的幻影籠罩著四周的敵人,正是迅雷劍法第十五式" + HIB + "『無影式』" + HIW + ",周圍敵人紛紛退卻..." + NOR,
        "dodge":   40,
        "parry":   80,
        "damage":   120,
        "force":    70,
        "damage_type" : "割傷",
]),

([ "action" : HIW + "$N將手中的$w舞得更急,使出迅雷劍法第十六式" + HIB + "『無蹤式』" + HIW + ",劍法快的連劍的蹤影都看不到只聽一聲慘號$n已被刺傷!。" + NOR,
        "dodge":    40,
        "parry":   80,
        "damage":   130,
        "force":    80,
        "damage_type" : "刺傷",
]), 

([ "action" : HIW + "$N使出迅雷劍法之最" + HIB + "『由幻返真』" + HIW + ",劍法之快,招式之辣,實已令人匪夷所思,所刺出的每一招皆令敵人受到重創" + NOR,
        "dodge":    40,
        "parry":   80,
        "damage":   150,
        "force":    80,
        "damage_type" : HIB + "迅雷劍傷" + NOR,
]),

});

void create()
{
   seteuid(getuid());
   set_name(HIB + "迅雷劍" + NOR,({"thunder_sword"}));
   set_weight(100);
   init_sword(115);
   if( clonep() )
      set_default_object(__FILE__);
   else
   {
      set("unit", "把");
    //set("wield_as", ({ "sword", "secondhand sword" }));
      set("long","
迅雷劍,劍身呈藍色,其重量和材質皆恰到好處,宛若當年風清揚賴以成名的迅雷
劍再現。若非其恰到好處的重量和鑄法,便難以發揮迅雷劍法之精奧,也難以承受
迅雷劍法的威力。
");
      set("value",200000);
      set("no_auc",1);
      set("no_give",1);
      set("no_sell",1);
      set("no_drop",1);
      set("material", "crimsonsteel");
   }
   set("actions", (: __FILE__, "query_action" :) );
   //set("default_actions", (: call_other, __FILE__,"query_action" :));
   setup();
}

void init()
{
     add_action("doo_wield","wield");
     add_action("doo_unwield","unwield");
}

int doo_wield(string str)
{
    object me;
    me=this_player();
    if(str=="all")
    return 1;

    else if(str!="thunder_sword")
    return 1;

    else if(!me->query("quest/tunder_sword",1)) {
    tell_object(me,"你沒有學會迅雷劍法，無法駕馭此劍。\n");
    return 1;
                                           }
    else if(me->query("class")!="swordsman")    { 
    tell_object(me,"你的職業不是劍士，幹嘛拿劍?\n");
    return 1;
                                           }
    else if(me->query_skill("sword",1) < 95)    {
    tell_object(me,"你的基礎劍術不夠，無法駕馭此劍。\n");
    return 1;
                                           }
    else {
    message_vision("$N手中一閃,已將繞在腰間的" + HIB + "迅雷劍" + NOR + "威風凜凜的拿在手中。\n",me);
    tell_object(me,"使用迅雷劍就不能使用其他劍術(en sword none)\n"); 
    return 0; 
         }   
}

int doo_unwield(string str)
{
    object me;
    me=this_player();
    if(str == "tunder_sword" || str=="sword" || str=="all")
    message_vision("$N一運內力,手中的" + HIB + "迅雷劍" + NOR + "剎時變成一把綿劍,$N順勢把它纏回腰間。\n",me);
    me->unwield_tunder_sword();
}                       

string query_parry_msg(string limb)
{
   return parry_msg[ random( sizeof( parry_msg))];
}


mapping query_action(object me, object weapon)
{
        mapping do_action;
        string arg;
        mixed all;
        object *enemy,who,room,weaponn,obj;
        string actionn;
        int i, j, k, gin, kee,sen,force,turn,l;
        force=me->query("force");
        gin=me->query("gin");
        sen=me->query("sen");
        turn=(force/100)+(gin/30)+(sen/30);
        if(turn >20) turn =20;
        if( random(4) == 0 && me->query("sen") > 40 && me->query("gin") > 40 && me->query("force") > 300) {
            enemy = me->query_enemy();
              for(i=0; i<sizeof(enemy); i++) {
                for(j=0; j<turn; j++) {
                    
                    do_action = action[random(sizeof(action))];
                    actionn = "\n";
                    actionn += do_action["action"];
		    if( weaponn=me->query_temp("weapon") )
                        actionn = replace_string(actionn, "$w", weaponn->name());
                    message_vision(actionn, me, enemy[i]);
                    if( random(me->query("combat_exp")) >
                        random(enemy[i]->query("combat_exp"))/5 ) {
                        message_vision("\n$N閃躲不及, 被這一劍刺中了要害。\n" , enemy[i]);
                        enemy[i]->receive_damage("kee",80,me);
                        enemy[i]->add("eff_kee",-30);
                        me->add("force",-12);
                        COMBAT_D->report_status(enemy[i]);
                                                                   }
                    else message_vision("\n$N人比劍快, 驚險地閃過了這一招。\n" , enemy[i]);
                                        }
                                              }
            if( random(me->query_cps()) < 4 ) {
                me->add("sen", -30);
                me->add("gin",-30);
                me->add("force",-200);
                tell_object(me,HIW + "\n你使出一十七招迅雷劍後,由於定力不夠,內力紊亂,大損精神。\n\n" + NOR);
                me->start_busy(1);
                                                }
                  
           else if (random(100) > 1 && me->query("quest/tunder_sword_18")==1 ){
message_vision(HIR + "\n\n$N一連使出一十七招迅雷劍法後，結合了天時地利人和之氣
仰天發出長嘯～～

" + HIB + "忽然間天地一片昏暗，烏雲密佈的上空雷電交作，$N的迅雷劍與$N
合為一體不斷地閃著耀眼的白光，正是一切都將毀滅的前兆!!

" + HIR + "驀然聽到$N一聲大喝：大開殺戒，我方迴避!!啊～～～～～
\n" + NOR,me);
        room = environment(me);
        all = all_inventory(room);
        for( l = 0 ; l < sizeof(all) ; l++){
        obj = all[l];
        obj->remove_all_killer();
                                           }
        call_out("attack",5,me);

                                                                               }

           me->add("force",-200);
                                                                                                   }
        return action[random(sizeof(action))];
}
int attack(object me){
 string arg;
 object who,obj,room,*all;
 int i;
 room = environment(me);
 all = me->query_enemy(room);
 message_vision(HIR + "\n\n$N蓄足了體內的真氣，仰天長嘯其勢如龍吟，使出了" + HIB + "迅雷劍法" + HIR + "最後一招
\n\n                     " + HIB + "『霹   " + HIW + " 靂 " + HIB + "   摧 " + HIW + "   河" + HIB + "    嶽』!!!


" + HIW + "四周一片劍氣縱橫，$N配合著迅然的猛雷勾動九地九天之氣，使大地為之
     動搖，波狀的劍氣以$N為中心向四周澎湃襲去。一片劍氣交錯後四周敵人
非死即碎，早已紛紛倒下....\n\n\n",me);
 for( i = 0 ; i < sizeof(all) ; i++){
   obj = all[i];

   if(obj!=me){
   obj->set("kee",6);
   obj->set("gin",6);
   obj->set("sen",6);
   obj->unconcious();
              }
                                    }
   me->set("force",0);
   return 1;
}

int query_autoload()
{
if(this_player()->query("family/family_name")=="仙劍派" && this_player()->query("quest/tunder_sword",1)==1)
return 1;
}

