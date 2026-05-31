//終於大致完成了...
//在此感謝frequency appo neverend wade的幫忙
//唔...還有感謝chan的一些敘述 :Q
//今日為 2003.04.10 完成pkdog-staff   by pana
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void delay1 (object me, object target, object  weapon, int damage);
void delay2 (object me, object target, object  weapon, int damage);
void one (object me, object target, object  weapon, int damage);
void two (object me, object target, object  weapon, int damage);
void three (object me, object target, object  weapon, int damage);
void berserk (object me, object target, object  weapon, int damage);
void sevenkill(object me, object weapon, int damage);
void peratt (object me, object target, object  weapon, int damage);

mapping *action =
({
//1
        ([
        "action" : 
        "$N將$w伸出，一招"HIW"『"HIM"撥狗朝天"HIW"』"NOR"，將杖身挑著$n的身子甩了上來！杖頭直翻起來，砸向$n額角！",
                "damage" : 200,
                "force" : 50,
                "damage_type" : "擊傷",
                "dodge" : -50,
                "parry" : -30,
                "post_action" : (: peratt :),
        ]),
//2
    ([
        "action" :
        "$N哼的一聲，一式"HIW"『"HIC"棒打雙獒"HIW"』"NOR"使了出來，身影仿彿幻化成兩個，以迅雷之勢，雙雙擊向了$n的破綻，使$n左滯右肘！",
                "damage" : 200,
                "force" : 80,
                "damage_type" : "擊傷",
                "dodge" : -50,
                "parry" : -30,
                "post_action" : (: peratt :),
        ]),
//3
    ([
        "action" :
        "$N持$w使了一記"HIW"『人狗爭食』"NOR"，忽地翻身一滾$w伸處，向$n腰間挑去！",
                "damage" : 250,
                "force" : 120,
                "damage_type" : "擊傷",
                "dodge" : -60,
                "parry" : -30,
                "post_action" : (: sevenkill :),
        ]),
//4
    ([
        "action" :
        "$N在這險象環生之際，隻手舉$w朝天揮出"HIW"『"HIG"倚杖喝狗"HIW"』"NOR"，棍中夾經硬捶$n後心！",
                "damage" : 220,
                "force" : 100,
                "damage_type" : "擊傷",
                "dodge" : -30,
                "parry" : -10,
                "post_action" : (: sevenkill :),
        ]),
//5
    ([
        "action" :
        "$N倏然間使出一式"HIW"『"HIB"狗急跳牆"HIW"』"NOR"，手中$w以無比絕倫的速度挺向$n的下盤，$N趁勢將$w上挑，重重擊向$n的後心！",
                "damage" : 150,
                "force" : 80,
                "damage_type" : "擊傷",
                "dodge" : -20,
                "parry" : -20,
                "post_action" : (: sevenkill :),
        ]),
//6
    ([
        "action" :
        "$N氣沉心靜，手中$w微動，剎那間一式"HIW"『"HIR"斜打狗背"HIW"』"NOR"使了出來，手中$w氣勢萬鈞地向$n的胸口點了過去！",
                "damage" : 180,
                "force" : 80,
                "damage_type" : "擊傷",
                "dodge" : -50,
                "parry" : -10,
                "post_action" : (: sevenkill :),
        ]),
//7
    ([
        "action" :
        "$n以絕強的攻勢由上攻向$N，$N在這險象環生之際，手持$w揮出"HIW"『"BCYN"快擊狗臀"NOR""HIW"』"NOR"，棒棒戳向$n後心！",
                "damage" : 220,
                "force" : 150,
                "damage_type" : "擊傷",
                "dodge" : -40,
                "parry" : -20,
                "post_action" : (: peratt :),
    ]),
//8
    ([
        "action" :
        "$n捨命的攻擊$N，只見$N手端$w使出"HIW"『"BMAG"黃狗撒尿"NOR""HIW"』"NOR"，棒勢一迴後狠狠地擊向叫$n的臉部！",
                "damage" : 170,
                "force" : 75,
                "damage_type" : "擊傷",
                "dodge" : -35,
                "parry" : -30,
                "post_action" : (: peratt :),
        ]),
//9
    ([
        "action" :
        "$N收攝心神，使出打狗棒法最高的境界"HIW"『"BGRN"天下無狗"NOR""HIW"』"NOR"，$n只覺眼前一花，已被$N無數身影所籠罩，$N趁機揮舞著$w，以破山烈地之勢掃向$n﹗！",
                "damage" : 250,
                "force" : 200,
                "damage_type" : "擊傷",
                "dodge" : -40,
                "parry" : -30,
        ]),
//10
    ([
        "action" :
        "$N將$w橫舉胸前，左一招"HIW"『"BBLU"打草驚蛇"NOR""HIW"』"NOR"，右一招"HIW"『"BRED"撥草尋蛇"NOR""HIW"』"NOR"，分攻$n兩側，只見$n忽露破綻，叫聲：「著！」一棒打在$n的天靈蓋\上！",
                "damage" : 220,
                "force" : 200,
                "damage_type" : "擊傷",
                "post_action" : (: delay1 :),
                "dodge" : -50,
                "parry" : -40,
        ]),
//11
    ([
        "action" :
        "$N以絕快的身法，瞬間游走至$n的背後，隨即使出一招"HIR"『"HIW"棒壓狗背"HIR"』"NOR"，$w擊中$n的脊椎！",
                "damage" : 180,
                "force" : 90,
                "damage_type" : "擊傷",
                "dodge" : -30,
                "parry" : -20,
        ]),
//12
    ([
        "action" :
        "$N將手上的$w,看拙實巧直直剌向$n的$l，正是一招"HIW"『若隱若現』。",
                "damage" : 150,
                "force" : 75,
                "damage_type" : "擊傷",
                "dodge" : -15,
                "parry" : -10,
                "post_action" : (: peratt :),
        ]),
//13
    ([
        "action" :
        "$N躍至半空中,高舉手中的$w一招"HIW"『流星墜地』"NOR"﹐如流星般向$n的$l急劈而下",
                "damage" : 190,
                "force" : 60,
                "damage_type" : "擊傷",
                "dodge" : -25,
                "parry" : -30,
                "post_action" : (: sevenkill :),
        ]),
//14
    ([
        "action" :
        "$N將手中的$w,急劃圈圈一招"HIW"『無窮無盡』"NOR"﹐棒上的內勁向$n的$l襲去",
                "damage" : 140,
                "force" : 70,
                "damage_type" : "擊傷",
                "dodge" : -30,
                "parry" : -30,
        ]),
//15
    ([
        "action" : 
        "$N面對$n的攻擊使出"HIW"『封狗在外』"NOR"﹐將攻擊一封,利用$w向$n的$l一剌",
                "damage" : 110,
                "force" : 55,
                "damage_type" : "擊傷",
                "dodge" : -45,
                "parry" : -10,
                                "post_action" : (: delay2 :),
        ]),
//16
    ([
        "action" :
        "$N將手中的$w,由下往上挑起一招"HIC"『挑狗在天』"NOR"使$n被挑至空中並從旁向$l擊出！",
                "damage" : 210,
                "force" : 65,
                "damage_type" : "擊傷",
                "dodge" : -30,
                "parry" : -15,
        ]),
//17
    ([
        "action" : 
        "$N將內勁貫注至$w,"HIC"『狂風追雪』"NOR"﹐棒勁所形成的寒風向$n的$l襲去。",
                "damage" : 160,
                "force" : 80,
                "damage_type" : "擊傷",
                "dodge" : -25,
                "parry" : -20,
        ]),
//18
    ([
        "action" :
        "$N鼓盡全身內力,一招"HIC"『亂棒狂擊』"NOR"﹐手中的棒子向$n的$l亂擊而出！",
                "damage" : 180,
                "force" : 75,
                "damage_type" : "擊傷",
                "dodge" : -50,
                "parry" : -20,
                "post_action" : (: berserk :),
        ]),
//19
    ([
            "action" :
                HIC"$N雙眼一閉，無數呢喃聲嗡嗡而出，打亂了$n心神，$N手中兵器對著$n毫不留情的重擊而來！"NOR,
                "force" : 50,
                "dodge" : -30,
                "parry" : -20,
                "damage_type" : "擊傷",
                "post_action" : (: one :),
        ]),
//20
    ([
            "action" :
                "$N對著$n垂首默念："HIY"「棒迴掠地施妙手，橫打雙獒莫回頭。狗急跳牆如何打？快擊狗臀劈狗尾。」"NOR,
                "force" : 40,
                "dodge" : -30,
                "parry" : -30,
                "damage_type" : "擊傷",
                "post_action" : (: two :),
        ]),
//21
    ([
            "action" :
                HIR"$N雙手緊握棒子，將內力灌注於棒子，棒子幻出一陣強勁白光，日月為之失色！"NOR,
                "force" : 80,
                "dodge" : -50,
                "parry" : -50,
                "damage_type" : "擊傷",
                "post_action" : (: three :),
        ]),
        
});

int valid_enable(string usage)
{
        return usage=="staff"||usage=="parry";
}


int valid_learn(object me)
{
        object ob;
        if((int)me->query("max_force")<100)
        return notify_fail("你的內力不夠，不能練打狗棒法。\n");
        if((string)me->query_skill_mapped("force")!= "pkdog-force")
        return notify_fail("打狗棒法必須配合養狗經才能學習。\n");
                if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="staff")
        return notify_fail("你必須有棍才能練棍法。\n");
        return 1;
}


mapping query_action(object me, object weapon)
{
    mapping do_action;
    object *enemy, weaponn;
    string actionn;
    int i,j,k,kee,level;
    if((int)me->query_skill("pkdog-staff",1) >= 80 
        && random(me->query_kar()+me->query_cor()) > 30
		&& me->query("env/打狗連擊")=="YES")
{
        enemy = me->query_enemy(); 
        k = (int) (me->query_skill("pkdog-staff",1)/10);
        if (k>10) k=10;
        message_vision(HIM"$N一時殺了眼紅，朝著敵人連綿不絕地施展杖擊。\n"NOR,me);
        for(i=0;i<random(k)+1;i++)
        {
            for(j=0;j<sizeof(enemy);j++)
            {
                do_action = action[random(18)];  //此為計算連擊
                actionn = "\n";
                actionn += do_action["action"];
                if( weaponn=me->query_temp("weapon") )
                    actionn = replace_string(actionn, "$w", weaponn->name());
                message_vision(actionn, me, enemy[j]);
                
                if( random(me->query("combat_exp")) > random((enemy[j]->query("combat_exp"))/3))
                {
                    kee = enemy[j]->query("eff_kee");
                    enemy[j]->receive_wound("kee", kee/50,me);
                    message_vision(HIR "\n$N閃躲不及，頭上狠狠的被擊了個包，叫個不停。\n" NOR, enemy[j]);
                    COMBAT_D->report_status(enemy[j]);
                 }
                 else message_vision(HIY "\n$N勢比$n兇，反倒逃過了一擊。\n" NOR, enemy[j],me);
             }
         }
         if( random(me->query_cps()) < 10 ) 
         {
             me->add("sen", -10);                
             tell_object(me,HIW"\n你恣意揮棒，忘了打狗棒法基本精神，被洪七公賞了一巴掌，行動因而停了下來。\n\n"NOR);
             me->start_busy(1);
          }
    }

//此部份為隨機出招部份
    level = (int) me->query_skill("pkdog-staff",1);
    if(level > 0  && level < 30 )
        return action[random(7)];
    if(level >= 30  && level < 40 )
        return action[random(10)];
    if(level >= 40  && level < 50 )
        return action[random(13)];
    if(level >= 50 && level < 60 )
        return action[random(16)];
    if(level >= 60 && level < 80 )
        return action[random(19)];
    if(level >=80 && level <100 )
        return action[random(21)];
        return action[random(sizeof(action))];
}

void delay1 (object me, object target, object  weapon, int damage)
{
        int time=(random(me->query_kar()))/10+1;
        if (random((me->query("combat_exp"))*10) > random((target->query("combat_exp"))/5) &&
            random(me->query("max_force")) > random(target->query("max_force")))
            message_vision(HIW"\n$N被突如其來的招式嚇得不知所措，頓時慌了手腳！\n",target);
            target->start_busy(time);
                return;
}

void delay2 (object me, object target, object  weapon, int damage)
{
        int time=(random(me->query_kar()))/10+1;
        if (random((me->query("combat_exp"))*10) > random((target->query("combat_exp"))/5) &&
            random(me->query("max_force")) > random(target->query("max_force")))
            message_vision(HIC"\n$N使出打狗棒法「"HIR"纏"HIC"」字訣，棒頭在地下連點，連綿不絕地挑向$n的小腿和腳踝。\n"NOR,me,target);
                    message_vision(HIC"\n結果$n被$N攻的蹦跳不停，手忙腳亂！\n"NOR,me,target);
            target->start_busy(time);
                return;
}
void one (object me, object target, object weapon, int damage)
{
        int i;
        int karr = me->query_kar();
        int spii = me->query_spi();
        if (me->query("beggar/got_secret")==1 )
           {
        if ( (karr+spii) > random(80) )
        {
                message_vision("\n\n
          "HIC"《 "BMAG""HIW"天下之眾  唯吾獨尊 "NOR""HIC"》"NOR"
    $N"HIG"心神一定，把" +weapon->query("name")+ ""HIG"往地上一插，數道昊光激出，發出萬丈光芒"NOR"
                        
        "HIR"此時$N向$n奇襲而來，杖打落水狗，毫不留情。
          　　　　　　"HIW"～～　"HIY"喝　"HIW"～～\n"NOR,me,target);
                        for (i=1;i<=random(karr/5)+1;i++)
                        {
                                if (random(karr) > random(target->query_kar()))
                                {
                                        message_vision(CYN"\n$N硬生生地接下這一擊，口中鮮血久流不止。\n"NOR,target);
                                        target->receive_wound("kee",100*(1+random(3)),me);
                                        COMBAT_D->report_status(target);
                                }
                                else 
                                {
                                        message_vision(MAG"\n$N使出了空手奪白刃，破解了$n強大的攻擊！\n"NOR,target,me);
                                }
                        }
       }}
}



void two (object me, object target, object  weapon, int damage)
{
        // 變數宣告要跟程式分開至少一行，比較容易讀
        object *enemy;
        int i,j,corr,karr,ecor,ekar;
        
        // 程式在這兒.....
        // 可以把傳進來的變數先印一下
        // 每一行不要超過八十個字，寧可分成兩行
        enemy= me->query_enemy();
        i = sizeof(enemy);
        // 取得變數，先印一下。
        
        if (i > 0)
        {
        j = random(i);
        ecor = enemy[j]->query_cor();
        ekar = enemy[j]->query_kar();
        corr = me->query_cor();
        karr = me->query_kar();
        }
        if (me->query("beggar/got_secret")==1 )
        {
        message_vision(HIR"$N見機不可失，趕緊放出數隻狗撲向$n\n"NOR,me,enemy[j]);
        if (random(corr+karr) > (ecor+ekar)/2)
        {
                message_vision(HIR"$N手持"+weapon->query("name")+"口中唸唸有詞，數以千計的狗群朝$n直奔而來"NOR"
                        \n\t$N目露兇光使出了"HBMAG""HIW"萬 狗 毒 噬"NOR"，咬得$n全身體無完膚，多處中毒......\n\n",me,enemy[j]);
                enemy[j]->receive_wound("gin",random(3)*30+120);
                enemy[j]->apply_condition("dog",5);
                COMBAT_D->report_status(enemy[j]);
        }
        else
        {
                message_vision("\n\n$N"HIM"所放出的狗兒反被$n"HIM"瞪了一眼，夾著尾巴落慌而逃！\n"NOR,me,enemy[j]); 
        }
        }
}


void three (object me, object target, object  weapon, int damage)
{
        object *enemy;
        int mks,sklv,i,j;
        mks = me->query("MKS",1)/2000;
        sklv = me->query_skill("pkdog-force",1);

        enemy=me->query_enemy();
        if (i = sizeof(enemy) > 0)    j=random(i);      
        if(mks>5) mks=5;
        if(mks<1) mks=1;
        if (me->query("beggar/got_secret")==1)
        {
        if (mks > random(6) && sklv > 99)
        {
            if( environment(me) == environment(enemy[j]) )
            {
            message_vision(HIW"\n被"NOR"$N"HIW"所殺之怨靈在這時紛紛冒出，四處剎時陰氣森森，只見"NOR"$n"HIW"被無數怨靈團團包圍\n
                \n\n\t"HIR"～"HBBLU""HIW"惡"NOR""HIR"～"HBBLU""HIW"靈"NOR""HIR"～"HBBLU""HIW"噬"NOR""HIR"～"HBBLU""HIW"魂"NOR""HIR"～\n"NOR,me,enemy[j]);
              for (i=0 ; i < mks ; i++)
              {
                switch(i)
                {
                case 0:
                  if (random(2) == 1)
                  {
                  message_vision(HIR"惡靈伸出魔爪，往$n"HIR"雙眼刺去，$n"HIR"閃躲不及已經中招了。\n"NOR,me,enemy[j]);
                  enemy[j]->receive_wound("kee",100+random(mks)*20);
                  COMBAT_D->report_status(enemy[j]);
                  }else{
                  message_vision("$n"MAG"一個飛步躲開了惡靈的糾纏！\n"NOR,me,enemy[j]);
                  COMBAT_D->report_status(enemy[j]);
                  }
                        break;
                case 1:
                  if (random(2) == 1)
                  {
                  message_vision(HIB"惡靈帶著深深恨意，直奪$n"HIB"性命！\n"NOR,me,enemy[j]);
                  enemy[j]->receive_wound("sen",50+random(mks)*20);
                  COMBAT_D->report_status(enemy[j]);
                  }else{
                  message_vision("$n"MAG"一個飛步躲開了惡靈的糾纏！\n"NOR,me,enemy[j]);
                  COMBAT_D->report_status(enemy[j]);
                  }
                        break;
                case 2:
                  if (random(2) == 1)
                  {
                  message_vision(GRN"惡靈企圖將$n"GRN"撕成碎塊，只聽見$n"GRN"不斷的哀號聲．．．\n"NOR,me,enemy[j]);
                  enemy[j]->receive_wound("kee",100+random(mks)*20);
                  COMBAT_D->report_status(enemy[j]);
                  }else{
                  message_vision("$n"MAG"一個飛步躲開了惡靈的糾纏！\n"NOR,me,enemy[j]);
                  COMBAT_D->report_status(enemy[j]);
                  }
                        break;
                case 3:
                if (random(2) == 1)
                  {
                  int k = 500 + random(2) * 50;
                  message_vision(HIY"惡靈縛住$n"HIY"的脖子，將$n"HIY"的內力慢慢吸到自身，此時$n"HIY"的面已漸無血色！\n"NOR,me,enemy[j]);
                  enemy[j]->add("force",-k);
                  me->add("force",k);
                  COMBAT_D->report_status(enemy[j]);
                  }else{
                  message_vision("$n"MAG"一個飛步躲開了惡靈的糾纏！\n"NOR,me,enemy[j]);
                  COMBAT_D->report_status(enemy[j]);
                  }
                        break;
                case 4:
                  if (random(2) == 1)
                  {
                  message_vision(HIC"惡靈附身於$N，$N"HIC"藉由邪惡之力，對$n"HIC"施以狂擊！\n"NOR,me,enemy[j]);
                  enemy[j]->receive_wound("kee",200+random(mks)*20);
                  enemy[j]->receive_damage("gin",50+random(mks)*20);
                  enemy[j]->receive_damage("sen",50+random(mks)*20);
                  COMBAT_D->report_status(enemy[j]);
                  }else{
                  message_vision("$n"MAG"一個飛步躲開了惡靈的糾纏！\n"NOR,me,enemy[j]);
                  COMBAT_D->report_status(enemy[j]);
                  }
                        break;
                }
              }
            }
                return;
        }
        }
        else {message_vision(HIW"$N想要仿照洪七公的打狗秘招，結果畫虎不像反類犬，隨便朝著$n戳了幾下。\n"NOR,me,enemy[j]);}
}


string perform_action_file(string action)
{
        return CLASS_D("beggar")+"/pkdog-staff/"+action;
}

void berserk (object me, object target, object  weapon, int damage)
{
        int i,mks,ke,se,gi,spi;
        string aa;
        mapping aaa;
        object enemy=offensive_target(me);
        mks=me->query("MKS",1)/400 - 10;
                spi=me->query_spi();
                if (mks > 21) mks=21;
        if(!me->query_temp("berserk") && target->is_busy() && me->query("MKS",1) >8000
                        && me->query("combat_exp") >4000000 && random(spi) > 15)
        {
                message_vision(HIY"\n$N見機不可失，連忙運起十成功\力，毫不留情地對$n展開連擊！\n"NOR,me,target);
                me->set_temp("berserk",1);
                for (i=0;i<mks;i++)
                {
                        aaa=action[i];
                        aa = "\n";
                        aa += aaa["action"];
                if(weapon=me->query_temp("weapon") )
                aa=replace_string(aa, "$w", weapon->name());

                        message_vision(aa,me,enemy);
                        if(random(me->query("combat_exp")) > random(enemy->query("combat_exp"))/10)
                        {
                                message_vision(HIM"\n$n見$N殘暴之性，一時驚慌失措，等到發現時早已全身多處重傷。\n"NOR,me,enemy);
                                ke=enemy->query("max_kee",1)/20; 
                                gi=enemy->query("max_gin",1)/30;
                                se=enemy->query("max_sen",1)/30;
                                enemy->receive_wound("kee",ke);
                                enemy->receive_damage("gin",gi);
                                enemy->receive_damage("sen",se);
                                me->add("force",-30);
                                COMBAT_D->report_status(enemy);
                        }else{
                                message_vision(HIW"$n即時察覺不妙，連忙地躲了開來。\n"NOR,me,enemy);}
                        me->delete_temp("berserk");
                }
                message_vision(HIR"$N一時控制不了自身殺意，慘遭反噬，呆住在地上！\n"NOR,me);
        }
}

void peratt (object me, object target, object  weapon, int damage)
{
  int i,x,per,sklv;
  per=me->query_per();
  sklv=me->query_skill("force",1)/10;
  x=random(3);
  if(me->query("combat_exp")>9000000)
  {
    message_vision(HIY"\t$N突然幻化成嫦娥，由天媥媥飛舞而來。\n\n"NOR,me);
    message_vision(HIC"\n$N突然深情望著$n，情深款款訴說著甜言蜜語，殊不知．．．\n"NOR,me,target);
    message_vision(HIW"$N趁著$n沒有防備之時，偷襲$n全身上下各處弱點。\n\n\n"NOR,me,target);
    for (i=0;i<5;i++){
        switch(i)
        {
         case 0:
                message_vision(HIW"『"HIM"媚惑五術"HIW"』　　"HIR"媚\n"NOR,me);
                if ((int)me->query_cps() > random((int)target->query_cps()))
                {
                  message_vision(HIM"$N對著$n施展媚惑之力，使得$n的一切擊攻擊皆暫停了下來。\n"NOR,me,target);
                  target->start_busy(per/10);
                  COMBAT_D->report_status(target);
                }else{
                  message_vision(CYN"$n看清了$N這醜八怪的技倆，不屑地往$N身上吐了一口口水。\n"NOR,me,target);
                }
         break;
         case 1:
                 message_vision(HIW"『"HIM"媚惑五術"HIW"』　　"HIC"誘\n"NOR,me);
                 if (random((int)(me->query_cps()+me->query_per()))>target->query_cps())
                 {
                   message_vision(HIY"$N仿起打狗棒法裡，挨著身子貼近$n，$n見其美色因而失去防備。\n"NOR,me,target);
                                   damage=per*sklv;
                                   if(x==0){
                                           message_vision(HIC"$N藉此開始吸取$n的氣血。\n"NOR,me,target);
                                           target->receive_wound("kee",damage);}
                                   if(x==1){
                                           message_vision(HIC"$N藉此開始吸取$n的氣精。\n"NOR,me,target);
                                           target->receive_damage("gin",damage);}
                                   if(x==2){
                                           message_vision(HIC"$N藉此開始吸取$n的氣神。\n"NOR,me,target);
                                           target->receive_damage("sen",damage);}
                   COMBAT_D->report_status(target);
                 }else{
                   message_vision(HIW"$n驚覺不妙，連忙地一把推開了$N．．．．\n"NOR,me,target);
                 }
          break;
          case 2:
                  message_vision(HIW"『"HIM"媚惑五術"HIW"』　　"HIY"惑\n"NOR,me);
                  if(random((int)me->query_spi()) > 12)
                  {
                    message_vision("一陣"HIR"花雨"NOR"，$N緩緩從中走出，$n望著如此情景大為驚豔。\n",me,target);
                    message_vision(HIR"$N見此機不可失，硬是往$n的重要部位攻擊而去！\n"NOR,me,target);
                    damage=per*10+random(51);
                    target->receive_wound("kee",damage);
                    COMBAT_D->report_status(target);
                                  }else{
                    message_vision(HIR"$n心神一定，拆穿了$N的迷人之術。\n"NOR,me,target);
                  }
           break;
           case 3:
                   message_vision(HIW"『"HIM"媚惑五術"HIW"』　　"HIG"舞\n"NOR,me);
                   if((int)(me->query_per()+me->query_spi())> random(20))
                   {
                     message_vision(HIW"$N依著打狗棒法，舞起了翩翩漫舞，看得$n是樂不思蜀。\n"NOR,me,target);
                     message_vision(HIW"就在同時，$n身上的功\力不知覺地被$N吸走了許\多。\n"NOR,me,target);
                     target->receive_wound("gin",per*5);
                     target->add("force",-(int)(target->query("force")/5));
                     me->add("force",(int)(target->query("force")/5));
                     COMBAT_D->report_status(target);
                   }else{
                     message_vision(HIR"$n不理會$N的迷惑，往$N的臉上硬生生的賞了個巴掌。\n"NOR,me,target);
                   }
            break;
            case 4:
                    message_vision(HIW"『"HIM"媚惑五術"HIW"』　　"HIB"歸\n"NOR,me);
                    message_vision(HIC"$N用盡美色，試圖在此擊迷倒$n，結果．．．\n"NOR,me,target);
                    if(random(30)<per)
                    {
                      message_vision(HIG"$n扺擋不住$N的美色攻擊，終於臣服在$N的石榴裙下，因而倒地不起。\n"NOR,me,target);
                      target->receive_wound("kee",(int)(target->query("max_kee")/10));
                      target->apply_condition("no_power_e",3);
                                          me->receive_heal("kee",(int)(target->query("max_kee")/10));
                      me->receive_curing("kee",(int)(target->query("max_kee")/10));
                      COMBAT_D->report_status(target);
                    }else{
                      message_vision(HIR"所幸$n神智仍夠清醒，避開了$N這蛇蠍美人的致命攻擊\n"NOR,me,target);
                    }
             break;
                }}
        }
}


//七色狂殺
//威力考慮到MKS combat_exp enforce bellicosity 
void sevenkill(object me, object weapon, int damage)
{
        object *enemy,target;
        int i,j,k,l,cor,mks,limit,bell,heal;
        enemy=me->query_enemy();
        j=sizeof(enemy);
        l=sizeof(enemy);
        target = enemy[random(j)];
        mks=me->query("MKS")/3000;
        if(mks>7) mks = 7; //在21000時能出完全招
        limit=me->query_skill("pkdog-staff",1);
        bell=me->query("bellicosity");
        heal=target->query("kee")/10;
                cor=me->query_cor();
//打npc會較痛哦
//算了一下，打玩家若以5000+5000 /1000*12 + 10* 10000000/400000= 120+250 = 370
if(userp(target))
damage = random(((mks+bell)/1000)* (limit/20)) + 
         me->query("force_factor",1) * (int)me->query("combat_exp")/2000000;
else  
damage = ((mks+bell)/600)* (limit/10)+
         me->query("force_factor",1) * (int)me->query("combat_exp")/100000;
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/10)
        && me->query("class")=="beggar"
        && me->query("combat_exp") > 9000000 && limit > 119)
{
        message_vision(HIW"\n$N殺意狂起，萬杖幻影，團團圍繞$n，飛沙走石，夾帶數以萬計的肅殺之氣。\n"NOR,me,target);
        message_vision(HIW"\t\t～～"HIY"七　色　狂　殺"HIW"～～\n"NOR,me);
        for (i=0 ; i<mks ; i++)
        {
                switch( i )
                {
                case 0:
                        message_vision("\n\t "BLINK+HIR"紅　殺"NOR"\n\n      "HIW"～"HIR"血"HIW"～"HIR"染"HIW"～"HIR"長"HIW"～"HIR"空"HIW"～"NOR"
        "HIR"　╮　　　　　╭════╮　　╮　　╮　　 ╮╭╭═╮"NOR+HIW"
        "HIR"╰╬═══╯　╭══╦═╮　╭═╯╰╬╯　 ╭╯║　║"NOR+HIW"
        "BRED"　║　　　　　╭══╩═╯　　║　　║　　 ╯╰╰　╯　"NOR+HIW"
        "BRED"　║　　      ║　　　　　　╭═╯╰╬╯　╰╬╯╭╮   "NOR+HIW"
        "HIR"　║　　　    ║　　　　　　　║　　║　　║║║║║"NOR+HIW"
        "HIR"　╰═══╯  ╰════╯　╰╯　╰╩╯　╯╯╯╯╰"NOR+HIW"
                \n\n"NOR,me);
                                if(cor > random(40))
                                {
                message_vision(HIR"$N殺意凌厲，數以萬千針般似的殺氣在$n穿出了數百針孔。\n"NOR,me,target);
                target->receive_damage("kee",damage);
                COMBAT_D->report_status(target);
                                }else{
                message_vision(CYN"$n運氣震開了$N驚人的殺氣，冷眼地觀看$N的破綻。\n"NOR,me,target);
                                }
                        break;
                case 1:
                        message_vision("\n\t "BLINK+HIG"綠　殺"NOR"\n\n      "HIW"～"HIG"殺"HIW"～"HIG"神"HIW"～"HIG"痴"HIW"～"HIG"狂"HIW"～"NOR"
        "HIG"　╮　　　　　╭════╮　　╮　　╮　　 ╮╭╭═╮"NOR+HIW"
        "HIG"╰╬═══╯　╭══╦═╮　╭═╯╰╬╯　 ╭╯║　║"NOR+HIW"
        "BGRN"　║　　　　　╭══╩═╯　　║　　║　　 ╯╰╰　╯　"NOR+HIW"
        "BGRN"　║　　      ║　　　　　　╭═╯╰╬╯　╰╬╯╭╮   "NOR+HIW"
        "HIG"　║　　　    ║　　　　　　　║　　║　　║║║║║"NOR+HIW"
        "HIG"　╰═══╯  ╰════╯　╰╯　╰╩╯　╯╯╯╯╰"NOR+HIW"
                \n\n"NOR,me);
                                if(cor > random(40))
                                {
                message_vision(HIR"$N殺意凌厲，數以萬千針般似的殺氣在$n穿出了數百針孔。\n"NOR,me,target);
                target->apply_condition("no_power_e",3);
                COMBAT_D->report_status(target);
                                }else{
                message_vision(CYN"$n運氣震開了$N驚人的殺氣，冷眼地觀看$N的破綻。\n"NOR,me,target);
                                }
                        break;
                case 2:
                        message_vision("\n\t "BLINK+HIY"黃　殺"NOR"\n\n      "HIW"～"HIY"孤"HIW"～"HIY"鴻"HIW"～"HIY"遍"HIW"～"HIY"野"HIW"～"NOR"
        "HIY"　╮　　　　　╭════╮　　╮　　╮　　 ╮╭╭═╮"NOR+HIW"
        "HIY"╰╬═══╯　╭══╦═╮　╭═╯╰╬╯　 ╭╯║　║"NOR+HIW"
        "BYEL"　║　　　　　╭══╩═╯　　║　　║　　 ╯╰╰　╯　"NOR+HIW"
        "BYEL"　║　　      ║　　　　　　╭═╯╰╬╯　╰╬╯╭╮   "NOR+HIW"
        "HIY"　║　　　    ║　　　　　　　║　　║　　║║║║║"NOR+HIW"
        "HIY"　╰═══╯  ╰════╯　╰╯　╰╩╯　╯╯╯╯╰"NOR+HIW"
                \n\n"NOR,me);
                                if(cor > random(40))
                                {
                message_vision(HIR"$N殺意凌厲，數以萬千針般似的殺氣在$n穿出了數百針孔。\n"NOR,me,target);
                target->add("force",-(damage*2));
                                target->receive_damage("kee",damage/2);
                                me->add("force",damage*2);
                COMBAT_D->report_status(target);
                                }else{
                message_vision(CYN"$n運氣震開了$N驚人的殺氣，冷眼地觀看$N的破綻。\n"NOR,me,target);
                                }
                        break;
                case 3:
                        message_vision("\n\t "BLINK+HIM"紫　殺"NOR"\n\n      "HIW"～"HIM"豪"HIW"～"HIM"氣"HIW"～"HIM"千"HIW"～"HIM"丈"HIW"～"NOR"
        "HIM"　╮　　　　　╭════╮　　╮　　╮　　 ╮╭╭═╮"NOR+HIW"
        "HIM"╰╬═══╯　╭══╦═╮　╭═╯╰╬╯　 ╭╯║　║"NOR+HIW"
        "BMAG"　║　　　　　╭══╩═╯　　║　　║　　 ╯╰╰　╯　"NOR+HIW"
        "BMAG"　║　　      ║　　　　　　╭═╯╰╬╯　╰╬╯╭╮   "NOR+HIW"
        "HIM"　║　　　    ║　　　　　　　║　　║　　║║║║║"NOR+HIW"
        "HIM"　╰═══╯  ╰════╯　╰╯　╰╩╯　╯╯╯╯╰"NOR+HIW"
                \n\n"NOR,me);
                                if(cor > random(40))
                                {
                message_vision(HIR"$N殺意凌厲，數以萬千針般似的殺氣在$n穿出了數百針孔。\n"NOR,me,target);
                target->receive_damage("sen",damage);
                COMBAT_D->report_status(target);
                                }else{
                message_vision(CYN"$n運氣震開了$N驚人的殺氣，冷眼地觀看$N的破綻。\n"NOR,me,target);
                                }
                        break;
                case 4:
                        message_vision("\n\t "BLINK+HIB"藍　殺"NOR"\n\n      "HIW"～"HIB"月"HIW"～"HIB"掛"HIW"～"HIB"琝"HIW"～"HIB"壎"HIW"～"NOR"
        "HIB"　╮　　　　　╭════╮　　╮　　╮　　 ╮╭╭═╮"NOR+HIW"
        "HIB"╰╬═══╯　╭══╦═╮　╭═╯╰╬╯　 ╭╯║　║"NOR+HIW"
        "BBLU"　║　　　　　╭══╩═╯　　║　　║　　 ╯╰╰　╯　"NOR+HIW"
        "BBLU"　║　　      ║　　　　　　╭═╯╰╬╯　╰╬╯╭╮   "NOR+HIW"
        "HIB"　║　　　    ║　　　　　　　║　　║　　║║║║║"NOR+HIW"
        "HIB"　╰═══╯  ╰════╯　╰╯　╰╩╯　╯╯╯╯╰"NOR+HIW"
                \n\n"NOR,me);
                                if(cor > random(40))
                                {
                message_vision(HIR"$N殺意凌厲，數以萬千針般似的殺氣在$n穿出了數百針孔。\n"NOR,me,target);
                target->receive_damage("gin",damage);
                COMBAT_D->report_status(target);
                                }else{
                message_vision(CYN"$n運氣震開了$N驚人的殺氣，冷眼地觀看$N的破綻。\n"NOR,me,target);
                                }
                        break;
                case 5:
                        message_vision("\n\t "BLINK+HIC"青　殺"NOR"\n\n      "HIW"～"HIC"長"HIW"～"HIC"空"HIW"～"HIC"一"HIW"～"HIC"青"HIW"～"NOR"
        "HIC"　╮　　　　　╭════╮　　╮　　╮　　 ╮╭╭═╮"NOR+HIW"
        "HIC"╰╬═══╯　╭══╦═╮　╭═╯╰╬╯　 ╭╯║　║"NOR+HIW"
        "BCYN"　║　　　　　╭══╩═╯　　║　　║　　 ╯╰╰　╯　"NOR+HIW"
        "BCYN"　║　　      ║　　　　　　╭═╯╰╬╯　╰╬╯╭╮   "NOR+HIW"
        "HIC"　║　　　    ║　　　　　　　║　　║　　║║║║║"NOR+HIW"
        "HIC"　╰═══╯  ╰════╯　╰╯　╰╩╯　╯╯╯╯╰"NOR+HIW"
                \n\n"NOR,me);
                while(j--)
                {
                                if(cor > random(40))
                {
                                message_vision(HIR"$N殺意凌厲，數以萬千針般似的殺氣在$n穿出了數百針孔。\n"NOR,me,enemy[j]);
                enemy[j]->receive_wound("kee",damage);
                me->receive_heal("kee",heal);
                me->receive_curing("kee",heal);
                COMBAT_D->report_status(enemy[j]);
                                }else{
                                        message_vision(CYN"$n運氣震開了$N驚人的殺氣，冷眼地觀看$N的破綻。\n"NOR,me,target);
                                }
                                                                }
                        break;
                case 6:
                        message_vision("\n\t "BLINK+HIW"白　殺"NOR"\n\n      "HIW"～盡～化～塵～埃～"NOR"
        "HIW"　╮　　　　　╭════╮　　╮　　╮　　 ╮╭╭═╮"NOR+HIW"
        "HIW"╰╬═══╯　╭══╦═╮　╭═╯╰╬╯　 ╭╯║　║"NOR+HIW"
        "BWHT"　║　　　　　╭══╩═╯　　║　　║　　 ╯╰╰　╯　"NOR+HIW"
        "BWHT"　║　　      ║　　　　　　╭═╯╰╬╯　╰╬╯╭╮   "NOR+HIW"
        "HIW"　║　　　    ║　　　　　　　║　　║　　║║║║║"NOR+HIW"
        "HIW"　╰═══╯  ╰════╯　╰╯　╰╩╯　╯╯╯╯╰"NOR+HIW"
                \n\n"NOR,me);
                                while(l--)
                                {
                if(cor > random(40)){
                message_vision(HIR"$N殺意凌厲，數以萬千針般似的殺氣在$n穿出了數百針孔。\n"NOR,me,enemy[l]);
                enemy[l]->receive_wound("kee",damage/2);
                target->start_busy(2);
                COMBAT_D->report_status(enemy[l]);
                                }else{
                                        message_vision(CYN"$n運氣震開了$N驚人的殺氣，冷眼地觀看$N的破綻。\n"NOR,me,enemy[l]);
                                }
                                                                }
                        break;
                }//switch
        }//for
}//if
}
