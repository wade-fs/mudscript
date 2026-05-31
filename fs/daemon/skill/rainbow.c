//Designed by Wataru    2000/9/6
//進階職業---忍者
//專用招式之一:遠距離攻擊類    漫天花雨手法
//特色，根據手中持有武器的不同，將有不同種類的攻擊
//fs沒有氣勁(或稱鬥氣)存在，只好以花費靈力為主，這裡靈力就有一點像是鬥氣
//所有的威力與計算公式都會在調整，以後會考慮敵我雙方的能力來決定命中度
//一般而言會以dodge為主要考量，威力會參考『真.黑牙神功』的威力來決定
//且公式的計算會再多樣化一點，特功的傷害也會再調整
//目前的威力，都只是為實驗這樣的skills，是否可以做出來
//最後，會再加上所謂的『技巧熟練度』，用不同類的武器，有不同的熟練度
//然後，熟練度的高低，也會決定特功出現機率，與特功威力
//熟練度會是隱藏屬性，目前會先加上去，但是目前只設定點數
//如下if (me->query("rainbow/fly/exp"))
//              me->add("rainbow/fly/exp",1);
//      else
//              me->set("rainbow/fly/exp",1);
//至於後來熟練度是換算成等級，或是說會受限於某一些skills的等級，到時候在設定
//當然，會另外作一個漫天花雨的特功，給每一類的武器(這三類)
//等熟練度到達一定等級，該特功的絕招才會出現
//例如可以 perform throwing.XXXXX   (此特功沒有等級可以練)
//XXXX要等武器熟練度到一定程度才會出現，且裡面的function也會check熟練度
#include <combat.h>
#include <ansi.h>
inherit SKILL;
void thunder_shot(object,object,object,int);
void double_dragon(object,object,object,int);
void pilibomb(object,object,object,int);
void world_rain(object,object,object,int);
void live_snake(object,object,object,int);
void shock_wave(object,object,object,int);

mapping *action = ({
        (["action":HIW"$N氣集丹田，手中的$w閃出異樣的光芒，"+
                        "$n感到一陣不安，彷彿危機四伏\n"+
                        "然而一切似乎都太晚，因為$w化成一到光芒，"+
                        "朝著$n而去，一切都是那麼的快令人無法置信\n"+
                        "$N施展傳說中的漫天花雨手法----"+HIM+"『電光一閃』"NOR,
                "dodge":        -20,
                "damage":       250,
                "force":         50,
                "parry":        -10,
                "damage_type" : "燒傷",
                "post_action":  (: thunder_shot :),
        ]),
        (["action":HIW"$n眼前一花，已經失去了$N的身影，"+
                        "$n定睛往四周搜尋而去，想要發現$N的存在\n"+
                        "正當搜尋之時，$n發現自己犯了一個很大的錯誤"+
                        "因為背後已經出現兩道破空之聲!!!\n"+
                        "$N利用這一個空檔，氣運雙手的$w之上，\n"+
                        "使出漫天花雨手法----"+HIM+"『冰炎雙龍』"NOR,
                "dodge":        -20,
                "damage":       250,
                "force":        50,
                "parry":        -5,
                "damage_type" : "凍傷",
                "post_action":(: double_dragon :),
        ]),
        (["action":HIW"$N利用分功\化影神功\幻化出數道身影，"+
            "消失在$n眼前了!!!!\n"+
            "正當$n為眼前變化所驚嚇到時，$N身影已經出現在高空中\n"+
            "手中已經出現武林傳說中的強力火器『$w』蓄勢待發!!!!\n"+
            "$n發現情況不妙，然而$N已經施展漫天花雨手法----"+
                HIM"『雷霆旋風』\n"NOR,
                "dodge":        -20,
                "damage":       150,
                "force":        50,
                "parry":        -10,
            "damage_type" : "燒傷",
                "post_action":(: pilibomb :),
        ]),
(["action":HIW"$N怒吼一聲，混和體內的殺氣與鬥氣，爆出強烈鬥氣運轉全身\n"+
        "$N看來打算施展武林傳說中的神技，漫天花雨手法---"+HIM+
        "『絕世花雨』\n"NOR,
                "dodge":        -10,
                "damage":       150,
                "force":        100,
                "parry":        -20,
            "damage_type" : "燒傷",
                "post_action":(: world_rain :),
        ]),
(["action":HIW"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
        "$N用漫天花雨手法--"+HIM+"『漫游天際』"+HIW"去操控手中的$w \n"+
        "$w宛如靈蛇出洞一般，詭異的行動令$n，備感壓力，難以反應\n"+
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"NOR,
                "dodge":        -10,
                "damage":       350,
                "force":        100,
                "parry":        -20,
                "damage_type" : "射傷",
                "post_action":(: live_snake :),
        ]),
(["action":HIW"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
        HIW"$N將鬥氣施展於$w，配合漫天花雨手法--"+HIM+"『天地無用』\n"+
        HIW"$w高速的旋轉起來，並且閃耀著魔幻般的光芒，令人目不瑕己\n"+
        HIW"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"NOR,
                "dodge":        -10,
                "damage":       400,
                "force":        100,
                "parry":        -20,
                "damage_type" : "射傷",
                "post_action":(: shock_wave :),
        ]),
(["action":"$N一招「風起雲湧」﹐射出的$w以極端的速度飛往$n的$l去",
             "dodge":        -15,
             "damage_type" : "射傷",
                "damage":       100,
                "force":        100,
                "parry":        -10,
        ]),
});

int valid_learn(object me)
{
        object ob;
        //檢查是否有解過忍者
        if ( me->query("quest/ninja") != 1)
                return notify_fail("想學？等你有資格了在說吧!!\n");
        //以後這裡還要加上檢查，如果有學dagger方面的，就不可以學這一招
        //或者是說，加上檢查老師的部分
        if(me->query_skill("throwing",1) <100)
                return notify_fail("想要學漫天花雨手法？ 技巧這麼差，改天在來吧。\n");

        if( !(ob = me->query_temp("weapon"))    ||(string)ob->query("skill_type")!="throwing")
                return notify_fail("拿點暗器吧....不然你要怎麼學？\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" || usage=="parry";
}

mapping query_action(object me, object weapon)
{//這裡就是用來決定武器類型與特攻類型的地方
        int wea,i;
        object ob;

        ob = me->query_temp("weapon");
        wea= ob->query("fly-type");

        //先檢查武器的飛行種類，來決定到底是哪一種武器，自然會有不同的特攻與敘述

        //1:輕型暗器    容易取得，威力弱，發出特功時，對手容易busy
        //2:火器類      取得困難，威力強，發出特功時，本身也很容易busy，但可以對付全體
        //3:鎖鏈類      普通，威力普通，特功也普通
switch(wea)
        {//因為目前東西不夠多，所以招式自然也不多
                case 1: //0-1   目前僅有2招
                        return action[random(2)];
                case 2: // 2-3  目前僅有2招
                        return action[random(2)+2];
                case 3: // 4-5  目前僅有2招
                        return action[random(2)+4];
                default://寫個玩家用非專用武器的時候
                        return action[6];
        }
}

int practice_skill(object me)
{
        //暫定不能練習
        return 0;

        if( (int)me->query("kee") < 100
        ||      (int)me->query("force") < 50 )
                return notify_fail("你的內力或氣不夠﹐不能練漫天花雨手法。\n");
        me->receive_damage("kee", 100);
        me->add("force", -50);
        return 1;
}

/*目前不打算例外作perform
string perform_action_file(string action)
{
        return CLASS_D("killer")+"/rainbow/"+action;
}
*/
void thunder_shot(object me, object victim, object weapon, int damage)
{
  if( objectp(weapon) )
  {
        if( (int)weapon->query_amount()==1 )
        {
                  weapon->unequip();
         tell_object(me, "\n你的" + weapon->query("name") + "用完了﹗\n\n");
       }
       else
       {
        int am,sk_lv;

        sk_lv=me->query_skill("rainbow",1);
        if (me->query("atman") < 30)
                return ;
        if (me->query("rainbow/fly/exp"))
                me->add("rainbow/fly/exp",1);
        else
                me->set("rainbow/fly/exp",1);
        if (random(150) <sk_lv)
        {//初期幾乎不會發動此招，但是高手幾乎可以有很高的發動機率
                //輕型武器，以命中度為主，傷害力為輔，發動後，命中度95%
                if ( random(100)  < 94)
                {
                message_vision(sprintf(HIG"光芒在空氣中引起異樣的燃燒"+
                        "，出乎意料之外的轉向天空，衝破雲層"+
                        "異常的波動，\n引起了天地的變動"+weapon->query("name")
                +HIG"引爆閃電擊向$n，面對此變化$n根本無法反應!!!!\n"NOR)
                                ,me,victim);
                 victim->receive_damage("kee",50+5*sk_lv);
                 victim->start_busy(1);
                 me->add("atman",-30);
                 COMBAT_D->report_status(victim, 1);
                }
        }
                weapon->add_amount(-1);
        }
  }
}
void double_dragon(object me, object victim, object weapon, int damage)
{
  if( objectp(weapon) )
  {
        if( (int)weapon->query_amount()==1 )
       {
                     weapon->unequip();
         tell_object(me, "\n你的" + weapon->query("name") + "用完了﹗\n\n");
      }
     else
      {
        int am,sk_lv;

        sk_lv=me->query_skill("rainbow",1);
        if (me->query("atman") < 40)
                return ;
        if (me->query("rainbow/fly/exp"))
                me->add("rainbow/fly/exp",1);
        else
                me->set("rainbow/fly/exp",1);
        if (random(200)         <       sk_lv)
        {//初期幾乎不會發動此招，但是高手幾乎可以有很高的發動機率
                //輕型武器，以命中度為主，傷害力為輔，發動後，命中度90%
                if ( random(100)  < 89)
                {
                message_vision(sprintf(HIG"$n立刻轉身，打算閃躲開這一招"
                        +"，然而這又是所犯下的第二個錯誤!\n"
                        +HIR"火熱的紅光，由右側快速的接近$n，彷彿一條正在吐火的火龍\n"
                        +HIB"異樣的凍氣，由左側迅速的接近$n，彷彿一條渾身凍氣的冰龍\n"
                        +HIM"雙龍合為一體，衝向$n，給予$n難以置信的創傷\n"NOR),me,victim);
                 victim->receive_damage("kee",100+7*sk_lv);
                 victim->receive_wound("kee",500);
                 victim->start_busy(1);
                 me->add("atman",-40);
                 COMBAT_D->report_status(victim, 1);
                }
        }
                weapon->add_amount(-2);
       }
   }
}

void pilibomb(object me, object victim, object weapon, int damage)
{
 object *target;
 int i,j;

 target=me->query_enemy();
 i=sizeof(target);

  if( objectp(weapon) )
  {
        if( (int)weapon->query_amount()==1 )
       {
                     weapon->unequip();
         tell_object(me, "\n你的" + weapon->query("name") + "用完了﹗\n\n");
      }
     else
      {//基本素招幾乎沒有什麼威力，因為火器不易取得，所以不一定每一次會使用
       //不過並沒有命中度可言，因為每一次一定會中，不過在於霹靂彈是否發動
        int am,sk_lv;

        sk_lv=me->query_skill("rainbow",1);
        if (me->query("atman") < 30)
                return ;
        if (me->query("rainbow/bomb/exp"))
                me->add("rainbow/bomb/exp",1);
        else
                me->set("rainbow/bomb/exp",1);
        if (    random(sk_lv) > 70)     //發動機率很低 lv70以下沒有發動機率
        {
                //發動之後，自己為了活命，必須要閃躲，所以會busy (2)
                message_vision(sprintf(weapon->query("name")+
        HIC"彷彿有生命似的，在場中迅速的旋轉起來，形成一層層由氣勁所構成的旋風\n"
        +"除了飛身到空中的$N之外，場內的人無一可以脫離此旋風氣場\n"
        +"眾人受制於旋風氣場無法逃離，且不斷被迫到旋風中心\n"
        +"這時候"+weapon->query("name")+"化成一道光球，由旋風中心擊下爆發!!!\n"NOR)
                                ,me,victim);
         for(j=0;j<i;j++)
         {//威力暫定如此，等以後的真.黑牙神功，分功化影神功出現後，再調整公式
                target[j]->receive_damage("kee",200+10*sk_lv);
                target[j]->receive_damage("kee",(10*sk_lv));
                COMBAT_D->report_status(target[j], 1);
         }
         me->start_busy(2);
         me->add("atman",-30);
         weapon->add_amount(-1);
        }
        else
        {//大部分應該是沒有發動的狀態，主要是用來嚇對手，讓對手busy
                message_vision(sprintf(weapon->query("name")+
        HIC"彷彿有生命似的，在場中迅速的旋轉起來，形成一層層由氣勁所構成的旋風\n"
        +"除了飛身到空中的$N之外，場內的人無一可以脫離此旋風氣場\n"
        +"眾人受制於旋風氣場無法逃離，且不斷被迫到旋風中心\n"
        +"這時候"+weapon->query("name")+HIC"化成一道光球，被$N收回手中\n"
        +"場內所有人嚇出一身冷汗，久久不能自己\n"NOR),me,victim);
         for(j=0;j<i;j++)
         {//威力暫定如此，等以後的真.黑牙神功，分功化影神功出現後，再調整公式
                target[j]->receive_damage("sen",random(3*sk_lv));
                target[j]->receive_damage("gin",random(3*sk_lv));
                COMBAT_D->report_status(target[j], 1);
                if (random(10) < 4)     //約有3成會busy
                target[j]->start_busy(2);
         }
        }
       }
   }
}


void world_rain(object me, object victim, object weapon, int damage)
{
 object *target;
 int i,j;

 target=me->query_enemy();
 i=sizeof(target);

  if( objectp(weapon) )
  {
        if( (int)weapon->query_amount()==1 )
       {
                     weapon->unequip();
         tell_object(me, "\n你的" + weapon->query("name") + "用完了﹗\n\n");
      }
     else
      {//基本素招幾乎沒有什麼威力，因為火器不易取得，所以不一定每一次會使用
       //不過並沒有命中度可言，因為每一次一定會中，不過在於霹靂彈是否發動
        int am,sk_lv;

        sk_lv=me->query_skill("rainbow",1);
        if (me->query("atman") < 60)
                return ;
        if (me->query("rainbow/bomb/exp"))
                me->add("rainbow/bomb/exp",1);
        else
                me->set("rainbow/bomb/exp",1);
        if (    random(sk_lv) > 80)     //發動機率很低 lv80以下沒有發動機率
        {
                //發動之後，自己為了活命，必須要閃躲，所以會busy (2)
                message_vision(sprintf(
                HIW"$N手中的"+weapon->query("name")+"化成四道不同色彩的光影射出\n"
                +HIR"場內的空氣似乎開始燃燒起來了，帶著高熱火焰的朱雀出現了!!!\n"
                +HIB"一道光影射入地下，並沒有爆發，但是卻引起強烈的地震!!\n"
                +HIG"在場地的另外一邊，破空之聲狂嘯而出，青龍光影幻化而現\n"
                +HIC"隨著青龍的出現，光影也幻化出白虎而出\n"
                +HIM"宛如幻影般的四道光影合為一體，在場內引起強烈的爆炸!!!\n"NOR)
                                ,me,victim);
         for(j=0;j<i;j++)
         {//威力暫定如此，等以後的真.黑牙神功，分功化影神功出現後，再調整公式
                target[j]->receive_damage("kee",200+random(12*sk_lv));
                target[j]->receive_wound("kee",(random(12*sk_lv)));
                COMBAT_D->report_status(target[j], 1);
         }
         me->start_busy(2);
         me->add("atman",-60);
         weapon->add_amount(-4);
        }
        else
        {//大部分應該是沒有發動的狀態，主要是用來嚇對手，讓對手busy
                message_vision(sprintf(HIW"$N手中的"+weapon->query("name")
                +"化成四道不同色彩的光影射出\n"
                +HIR"場內的空氣似乎開始燃燒起來了，帶著高熱火焰的朱雀出現了!!!\n"
                +HIB"一道光影射入地下，並沒有爆發，但是卻引起強烈的地震!!\n"
                +HIG"在場地的另外一邊，破空之聲狂嘯而出，青龍光影幻化而現\n"
                +HIC"隨著青龍的出現，光影也幻化出白虎而出\n"
                +HIM"然而宛如幻影般的四道光影，再次回到$N手中，\n一點事情都沒有發生"
                +HIM"不過場內的眾人早已被如此影像所驚嚇，幾乎無力再戰\n"NOR)
                                ,me,victim);
         for(j=0;j<i;j++)
         {//威力暫定如此，等以後的真.黑牙神功，分功化影神功出現後，再調整公式
                target[j]->receive_damage("sen",random(5*sk_lv));
                target[j]->receive_damage("gin",random(5*sk_lv));
                COMBAT_D->report_status(target[j], 1);
                if (random(10) < 3)     //約有2成會busy
                target[j]->start_busy(3);
         }
        }
       }
   }
}

void live_snake(object me, object victim, object weapon, int damage)
{
        int am,sk_lv;
        sk_lv=me->query_skill("rainbow",1);
        if (me->query("atman") < 35)
                return ;
        if (me->query("rainbow/chain/exp"))
                me->add("rainbow/chain/exp",1);
        else
                me->set("rainbow/chain/exp",1);
        if (random(180) <sk_lv)
        {       //初期幾乎不會發動此招，但是高手幾乎可以有很高的發動機率
                //鎖鏈武器，特性普通，發動後，命中度70%
                if ( random(100)  < 70)
                {
                message_vision(sprintf(weapon->query("name")
                +HIG"在$N的操控下，突然爆出強烈氣勁，將$n的武器彈開!!!!\n"
                +HIG"一股強大的壓力，宛如排山倒海一般"
                +"，朝$n而去，無從閃避，完全命中\n"NOR)
                                ,me,victim);
                 victim->receive_damage("kee",100+6*sk_lv);
                 victim->start_busy(1);
                 me->add("atman",-35);
                 COMBAT_D->report_status(victim, 1);
                }
        }
}

void shock_wave(object me, object victim, object weapon, int damage)
{
        int am,sk_lv;

        sk_lv=me->query_skill("rainbow",1);
        if (me->query("atman") < 45)
                return ;
        if (me->query("rainbow/chain/exp"))
                me->add("rainbow/chain/exp",1);
        else
                me->set("rainbow/chain/exp",1);
        if (random(180) <sk_lv)
        {       //初期幾乎不會發動此招，但是高手幾乎可以有很高的發動機率
                //鎖鏈武器，特性普通，發動後，命中度70%
                if ( random(100)  < 70)
                {
                message_vision(sprintf(weapon->query("name")
                +HIG"越轉越快，已經無法分辨到底是何種東西，"
                +"只見到一道光影在$n上空旋轉\n"
                +"$n感到難以呼吸，整個空氣被逐漸壓縮起來"
                +"，身體也越來越難以動彈\n"
                +"忽然"+weapon->query("name")+HIG+"靜止在空中不動了？\n"
                +"被壓縮的空氣，瞬間被釋放開來，"
                +"轉換成強大的衝擊波能量，將$N擊飛到空中!\n"NOR)
                                ,me,victim);
                 victim->receive_damage("kee",100+6*sk_lv);
                 victim->start_busy(1);
                 me->add("atman",-35);
                 COMBAT_D->report_status(victim, 1);
                }
        }
}

