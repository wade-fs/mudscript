#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void delay (object me, object target, object  weapon, int damage);
void one (object me, object target, object  weapon, int damage);
void two (object me, object target, object  weapon, int damage);
void three (object me, object target, object  weapon, int damage);

mapping *action =
({
//1
        ([
"action" : 
        "$N將$w伸出，一招"HIW"『"HIM"撥狗朝天"HIW"』"NOR"，將杖身挑著$n的身子甩了上來！杖頭直翻起來，砸向$n額角！",
                "damage" : 200,
                "force" : 50,
                "damage_type" : "擊傷",
        ]),
//2
    ([
        "action" :
        "$N哼的一聲，一式"HIW"『"HIC"棒打雙獒"HIW"』"NOR"使了出來，身影仿彿幻化成兩個，以迅雷之勢，雙雙擊向了$n的破綻，使$n左滯右肘！",
                "damage" : 200,
                "force" : 80,
                "damage_type" : "擊傷",
        ]),
//3
    ([
        "action" :
        "$N持$w使了一記"HIW"『人狗爭食』"NOR"，忽地翻身一滾$w伸處，向$n腰間挑去！",
                "damage" : 250,
                "force" : 120,
                "damage_type" : "擊傷",
        ]),
//4
    ([
        "action" :
        "$N在這險象環生之際，隻手舉$w朝天揮出"HIW"『"HIG"倚杖喝狗"HIW"』"NOR"，棍中夾經硬捶$n後心！",
                "damage" : 200,
                "force" : 100,
                "damage_type" : "擊傷",
        ]),
//5
    ([
        "action" :
	"$N倏然間使出一式"HIW"『"HIB"狗急跳牆"HIW"』"NOR"，手中$w以無比絕倫的速度挺向$n的下盤，$N趁勢將$w上挑，重重擊向$n的後心！",
                "damage" : 150,
                "force" : 80,
                "damage_type" : "擊傷",
        ]),
//6
    ([
        "action" :
        "$N氣沉心靜，手中$w微動，剎那間一式"HIW"『"HIR"斜打狗背"HIW"』"NOR"使了出來，手中$w氣勢萬鈞地向$n的胸口點了過去！",
                "damage" : 180,
                "force" : 80,
                "damage_type" : "擊傷",
        ]),
//7
    ([
        "action" :
        "$n以絕強的攻勢由上攻向$N，$N在這險象環生之際，手持$w揮出"HIW"『"BCYN"快擊狗臀"NOR""HIW"』"NOR"，棒棒戳向$n後心！",
                "damage" : 220,
                "force" : 150,
                "damage_type" : "擊傷",
		"post_action" : (:three:),
    ]),
//8
    ([
        "action" :
        "$n捨命的攻擊$N，只見$N手端$w使出"HIW"『"BMAG"黃狗撒尿"NOR""HIW"』"NOR"，棒勢一迴後狠狠地擊向叫$n的臉部！",
                "damage" : 150,
                "force" : 75,
                "damage_type" : "擊傷",
		"post_action" : (:three:),
        ]),
//9
    ([
        "action" :
        "$N收攝心神，使出打狗棒法最高的境界"HIW"『"BGRN"天下無狗"NOR""HIW"』"NOR"，$n只覺眼前一花，已被$N無數身影所籠罩，$N趁機揮舞著$w，以破山烈地之勢掃向$n﹗！",
                "damage" : 250,
                "force" : 200,
                "damage_type" : "擊傷",
		"post_action" : (:three:),
        ]),
//10
    ([
        "action" :
        "$N將$w橫舉胸前，左一招"HIW"『"BBLU"打草驚蛇"NOR""HIW"』"NOR"，右一招"HIW"『"BRED"撥草尋蛇"NOR""HIW"』"NOR"，分攻$n兩側，只見$n忽露破綻，叫聲：「著！」一棒打在$n的天靈蓋\上！",
                "damage" : 220,
                "force" : 200,
                "damage_type" : "擊傷",
                "post_action" : (: delay :),
        ]),
//11
    ([
        "action" :
        "$N以絕快的身法，瞬間游走至$n的背後，隨即使出一招"HIR"『"HIW"棒壓狗背"HIR"』"NOR"，$w擊中$n的脊椎！",
                "damage" : 180,
                "force" : 90,
                "damage_type" : "擊傷",
        ]),
//12
    ([
        "action" :
        "$N將手上的$w,看拙實巧直直剌向$n的$l，正是一招"HIW"『若隱若現』。",
                "damage" : 150,
                "force" : 75,
                "damage_type" : "擊傷",
        ]),
//13
    ([
        "action" :
        "$N躍至半空中,高舉手中的$w一招"HIW"『流星墜地』"NOR"﹐如流星般向$n的$l急劈而下",
                "damage" : 120,
                "force" : 60,
                "damage_type" : "擊傷",
        ]),
//14
    ([
        "action" :
        "$N將手中的$w,急劃圈圈一招"HIW"『無窮無盡』"NOR"﹐棒上的內勁向$n的$l襲去",
                "damage" : 140,
                "force" : 70,
                "damage_type" : "擊傷",
        ]),
//15
    ([
        "action" : 
        "$N面對$n的攻擊使出"HIW"『封狗在外』"NOR"﹐將攻擊一封,利用$w向$n的$l一剌",
                "damage" : 110,
                "force" : 55,
                "damage_type" : "擊傷",
        ]),
//16
    ([
        "action" :
        "$N將手中的$w,由下往上挑起一招"HIC"『挑狗在天』"NOR"使$n被挑至空中並從旁向$l擊出！",
                "damage" : 130,
                "force" : 65,
                "damage_type" : "擊傷",
        ]),
//17
    ([
        "action" : 
        "$N將內勁貫注至$w,"HIC"『狂風追雪』"NOR"﹐棒勁所形成的寒風向$n的$l襲去。",
                "damage" : 160,
                "force" : 80,
                "damage_type" : "擊傷",
        ]),
//18
    ([
        "action" :
        "$N鼓盡全身內力,一招"HIC"『亂棒狂擊』"NOR"﹐手中的棒子向$n的$l亂擊而出！",
                "damage" : 150,
                "force" : 75,
                "damage_type" : "擊傷",
        ]),

//19
    ([
        "action" : "1 \n",
        "post_action" : (: one :),
        ]),

//20
    ([
        "action" : "2 \n",
        "post_action" : (: two :),
        ]),

//21
    ([
        "action" : "3 \n",
	"post_action" : (:three:),
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
    if(random(10) > 6 && (int)me->query_skill("pkdog-staff",1) >= 100 && random(me->query_kar())+2 > 10)
    {
        enemy = me->query_enemy(); 
            k = (int) (me->query_skill("pkdog-staff",1)/10);
            if (k>10) k=10;
                message_vision(HIM"$N一時殺了眼紅，朝著敵人連綿不絕地施展杖擊。\n"NOR,me);
            for(j=1;j<sizeof(enemy)+1;j++)
        {
            for(j=0;j<sizeof(enemy);j++)
            {
                do_action = action[random(12)];  //此為計算連擊
                actionn = "\n";
                actionn += do_action["action"];
                if( weaponn=me->query_temp("weapon") )
                    actionn = replace_string(actionn, "$w", weaponn->name());
                message_vision(actionn, me, enemy[j]);
                
                if( random(me->query("combat_exp")) > random((enemy[j]->query("combat_exp"))/3))
                {
                    kee = enemy[j]->query("eff_kee");
                    enemy[j]->receive_wound("kee", random(kee/60),me);
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
        return action[random(5)];
    if(level >= 30  && level < 50 )
        return action[random(7)];
    if(level >= 50  && level < 70 )
        return action[random(10)];
    if(level >= 70 && level < 90 )
        return action[random(12)];
    if(level >= 90 && level < 110 )
        return action[random(15)];
    if(level >=110 )
      return action[random(5)+15];
     return action[random(sizeof(action))];
}


void delay (object me, object target, object  weapon, int damage)
{
        int time=(random(me->query_kar()))/10+1;
        if (random((me->query("combat_exp"))*10) > random((target->query("combat_exp"))/5) &&
                random(me->query("max_force")) > random(target->query("max_force")))
                message_vision(HIW"$N被突如其來的招式嚇得不知所措，頓時慌了手腳！\n",target);
            target->start_busy(time);
                return;
}

void one (object me, object target, object weapon, int damage)
{
        int i;
        int karr = me->query_kar();
        int spii = me->query_spi();
        if ( (karr+spii) > random(50))
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
                                        message_vision(CYN"$N硬生生地接下這一擊，口中鮮血久流不止。\n"NOR,target);
                                        target->receive_wound("kee",100*random(10),me);
                                        COMBAT_D->report_status(target);
                                }
                                else 
                                {
                                        message_vision(MAG"$N使出了空手奪白刃，破解了$n強大的攻擊！\n"NOR,target,me);
                                }
                        }
        }
}

void two (object me, object victim, object  weapon, int damage)
{
        int i,j,corr,karr,ecor,ekar;
        object room,*enemy;
        enemy= me->query_enemy();
        room = environment(me);
        enemy=me->query_enemy(room);
//        i = sizeof(enemy);
//        j = i;
//        ecor = enemy[j]->query_cor();
//        ekar = enemy[j]->query_kar();
        ecor = enemy->query_cor();
        ekar = enemy->query_kar();
        corr = me->query_cor();
        karr = me->query_kar();
        if (random(corr+karr) > (ecor+ekar)/2)
        {
		message_vision(HIR"$N手持"+weapon->query("name")+"口中唸唸有詞，數以千計的狗群朝$n直奔而來"NOR"
                        $N目露兇光使出了"HBMAG""HIW"萬狗毒噬"NOR"，咬得$n全身體無完膚，多處中毒......\n",me,enemy);
                enemy->receive_wound("gin",random(3)*30+120);
                enemy->apply_condition("dog",5);
                COMBAT_D->report_status(enemy,1);
        }
        else
        {
                message_vision("\n$N所放出的狗兒反被$n瞪了一眼，夾著尾巴落慌而逃！\n",me,enemy);
        }
}


void three (object me, object target, object  weapon, int damage)
{
	object *enemy;
        int mks,sklv,i,j;
        mks = me->query("MKS",1)/2000;
        sklv = me->query_skill("pkdog-force",1);

	enemy=me->query_enemy();
	j=random(sizeof(enemy));

        if(mks>5) mks=4;
	if(mks<1) mks=1;
	if (mks > random(7) && sklv > 120)
	{
	    if( environment(me) == environment(enemy[j]) )
	    {
	    message_vision("被$N所殺之怨靈在這時紛紛冒出，四處剎時陰氣森森，只見$n被無數怨靈團團包圍\n
                \n\n\t～惡～靈～噬～魂～\n",me,enemy[j]);
	      for (i=0 ; i <= mks ; i++)
	      {
		switch(i)
                {
		case 0:
		  if (random(2) == 1)
		  {
		  message_vision("惡靈伸出魔爪，往$n雙眼刺去，$n閃躲不及已經中招了。\n",me,enemy[j]);
		  enemy[j]->receive_wound("kee",100+random(mks)*20);
		  COMBAT_D->report_status(enemy[j]);
		  }else{
		  message_vision("$n一個飛步躲開了惡靈的糾纏！\n",me,enemy[j]);
		  COMBAT_D->report_status(enemy[j]);
		  }
			break;
		case 1:
		  if (random(2) == 1)
		  {
		  message_vision("惡靈帶著深深恨意，直奪$n性命！\n",me,enemy[j]);
		  enemy[j]->receive_wound("kee",100+random(mks)*20);
		  COMBAT_D->report_status(enemy[j]);
		  }else{
		  message_vision("$n一個飛步躲開了惡靈的糾纏！\n",me,enemy[j]);
		  COMBAT_D->report_status(enemy[j]);
		  }
			break;
		case 2:
		  if (random(2) == 1)
		  {
		  message_vision("惡靈企圖將$n撕成碎塊，只聽見$n不斷的哀號聲．．．\n",me,enemy[j]);
		  enemy[j]->receive_wound("kee",100+random(mks)*20);
		  COMBAT_D->report_status(enemy[j]);
		  }else{
		  message_vision("$n一個飛步躲開了惡靈的糾纏！\n",me,enemy[j]);
		  COMBAT_D->report_status(enemy[j]);
		  }
			break;
		case 3:
		if (random(2) == 1)
		  {
		  message_vision("惡靈縛住$n的脖子，勒得$n喘不過氣來！\n",me,enemy[j]);
		  enemy[j]->receive_wound("kee",100+random(mks)*20);
		  COMBAT_D->report_status(enemy[j]);
		  }else{
		  message_vision("$n一個飛步躲開了惡靈的糾纏！\n",me,enemy[j]);
		  COMBAT_D->report_status(enemy[j]);
		  }
			break;
		case 4:
		  if (random(2) == 1)
		  {
		  message_vision("惡靈附身於$N，$N藉由邪惡之力，對$n施以狂擊！\n",me,enemy[j]);
		  enemy[j]->receive_wound("kee",100+random(mks)*20);
		  COMBAT_D->report_status(enemy[j]);
		  }else{
		  message_vision("$n一個飛步躲開了惡靈的糾纏！\n",me,enemy[j]);
		  COMBAT_D->report_status(enemy[j]);
		  }
			break;
                }
	      }
	    }
		return;
	}
        else {message_vision("$N像發了瘋似的，在那兒跳來跳去，怪像中了邪！\n",me);return;}
}


 string perform_action_file(string action)
{
        return CLASS_D("beggar")+"/pkdog-staff/"+action;
}

