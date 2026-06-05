#include <ansi.h>

#include <login.h>
inherit NPC;

string do_ask (object me);
int random_move();

void create()
{
        seteuid (geteuid());
        set_name("九省總巡捕--林凌", ({ "cop head", "cop", "head" }) );
	set("nickname", "鐵鎖橫江");
        set("long", @LONG
眼前這位是江湖中人人聞名色變的九省總巡捕，他外號鐵鎖橫江
的由來可不是九省總巡捕逮捕殺人犯就好像駕船碰到鐵鎖橫江般地礙
手礙腳，而是所有江洋大盜一被九省總巡捕盯上，從此生活就有如鐵
鎖橫江，永遠也不得安寧。
    如果你有意向他挑戰，那你可得小心他對你採取極嚴厲的報負手
段。三十五年前他為了追捕汪洋大盜--滑不溜手--胡一刀曾經連續八
天八夜不睡，躲在船底的夾層裡，他的狠與毅力是跟他的外號相配合
的。如果你想知道有誰是他最想追捕的江洋大盜, 可以問他有關殺手
(killer)的事。
    你看到總捕頭口袋裡裝了不少金牌，難道那就是有名的 PK 執照
(pk license)嗎? 也許你可以跟他申請(apply) 一張來保身哦!
LONG
	);

	set( "age", 55);

        set("max_gin", 5000);
        set("max_kee", 5000);
        set("max_sen", 5000);
        set("max_atman", 9999);
        set("atman", 9999);
        set("max_force", 5000);
        set("force", 5000);
        set("max_mana", 5000);
        set("mana", 5000);

        set("str", 100);
        set("cor", 100);
        set("cps", 100);
        set("spi", 100);
        set("int", 100);
        set("con", 100);

	set( "force_factor", 3 );
        set("combat_exp", 5000000);
        set_skill("staff", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);

	// 技能
	//		1.怪物學過的技能: set_skill( "技巧名", 數值 );
	//		2.怪物施展的技能: map_skill( "技巧種類", "技巧名" );
	// set_skill("celestial", 10);
	// map_skill("force", "celestial");

	set("race", "人類");

	set( "gender", "男性");

        set("limbs", ({ "頭部", "身體", "右腳", "左腳", "前胸", "後背" }) );
        set("verbs", ({ "bite", "claw" }) );
	set("random_move",-1);
	set("chat_msg_combat", ({
	    CYN "九省總巡捕說道: 棄暗投明吧?!\n" NOR,
	    CYN "九省總巡捕說道: 你現在所說的一切, 將作為呈堂證供。\n" NOR,
	    CYN "九省總巡捕說道: 人吃五穀雜糧, 誰能無過?!\n" NOR,
	    CYN "九省總巡捕說道: 放下屠刀, 立地成佛, 乖乖受死吧。\n" NOR,
	}) );

	set("inquiry", ([
	    "killer"	:	(: do_ask :),
	    "殺手"	:	(: do_ask :),
	]) );

        set("chat_chance", 6);
        set("chat_msg", ({
	    CYN "九省總巡捕說道: 我生平最恨殺人放火的事了。\n" NOR,
	    CYN "九省總巡捕說道: 唉, 為了追捕汪洋大盜，害我殺孽頗重。\n" NOR,
	    CYN "九省總巡捕說道: 我不入地獄誰入地獄?\n" NOR,
	    CYN "九省總巡捕說道: 偶而做做壞事也就罷了, 別殺人喔。\n" NOR,
	    CYN "九省總巡捕說道: 別以為九省巡捕是叫假的。\n" NOR,
	    CYN "九省總巡捕說道: 你知道鐵鎖橫江的真義嗎?\n" NOR,
        }) );

        set_temp("apply/armor", 2);

        setup();
}

int random_move ()
{
  tell_room (environment(this_object()),
             CYN "九省總巡捕說道: 我走了...\n" NOR);
  ::random_move();
}

// 當有其他生物對這個人物下 kill 指令的時候﹐會呼叫這個附加函數
int accept_kill(object who)
{
  object	me;
  string	pker;

  me = this_object();
  pker = who->query("id");

  // 有 PK 執照就不被追殺....
  if (present ("pk license", who)) {
    say("九省總巡捕說道: 既然閣下喜歡殺人, 在下只好奉陪。\n");
    ::accept_kill(who);
    return 1;
  }

  if (!wizardp(who)) {	// 想打九省總巡捕? 不要命了嗎?
    if ( !PK_D->get_pk_time ( pker ) ) {
      if (PK_D->add_pker (pker, time()))
        message("system",
                CYN"九省總巡捕大聲叫道: "+who->short()+
                "竟敢公然侮辱法律向我挑戰!!\n"+
                "九省總巡捕大聲叫道: 我以鐵鎖橫江的的名號保證,"+
	        " 不抓他歸案誓不成佛!!\n"NOR,
                users()
        );
    }
    else {
      message("system",
              CYN"九省總巡捕大聲叫道: "+who->short()+
              "這江洋大盜碰到我不敢快逃走, 還敢找我單挑!!\n"+
              "九省總巡捕大聲叫道: 我以鐵鎖橫江的的名號保證,"+
              " 不抓他歸案誓不成佛!!\n"NOR,
              users()
      );

    }
  }
  return 1;
}

// 當有人用 give 指令給這個非玩家人物東西時﹐會呼叫這個附加函數
int accept_object(object who, object item)
{
  string	pker;

  if (item->query("id") == "pk license") {
    destruct (item);
    tell_object (who, "九省總捕頭告訴你: 好孩子, 想做個安份良民了啊!!\n"+
		      "總補頭想了想, 說道: 好吧, 我幫你保管 PK 執照。\n");
  }
  else
    tell_object (who, 
      CYN "九省總巡捕告訴你: 你想賄賂我? 難不成你把我看成貪官污吏?!\n" NOR);

  return 1;
}

// 當這名人物殺死一個敵人的時候會呼叫這個附加函數
void killed_enemy(object who)
{
  if ( PK_D->delete_pker (who->query("id")) ) 
    shout (CYN"九省總巡捕大聲叫道: 逮捕江洋大盜"+who->name()+"("+
           who->query("id")+")一名。\n");
}

string do_ask (object me)
{
  string	pkers, *pklist;
  int		i;

  pklist = PK_D->query_pk_list();
  if (sizeof (pklist)) {
    pkers = "\n";
    for (i=1; i<=sizeof (pklist); i++)
      pkers += i+" "+pklist[i-1]+"\n";
    return pkers;
  }
  else return CYN "最近江湖雖然風起雲湧, 但是海內綏平, 國境平安。\n" NOR;
}

void init ()
{
  object	ob;

  ::init();

  // 這一段利用 init 配合 call_out 來每一次心跳都檢查是否有人跑過來..
  // 注意, remove_call_out 是為了減少 bug....尤其對那種久久 call_out 
  // 一次的來說更重要, 例如 拍賣, 流血中毒等.....
  if ( interactive (ob=this_player()) && !is_fighting(ob)) {
    remove_call_out ("greeting");
    call_out ("greeting", 1, ob);
  }
  add_action ("do_apply", "apply");
}

void greeting (object who)
{
  object	ob;

  if (!who || environment(who) != environment()) return;
  if (PK_D->get_pk_time(who)) {	// 江洋大盜一名
    message_vision ("$N喝道: $n, 今天碰到我算你倒霉, 納命來吧!!\n",
		    ob=this_object(), who);
    ob->kill_ob(who);
    command("follow "+who->query("id"));
  }
}

int do_apply (string arg)
{
  if (!arg || arg != "license") {
    write ("九省巡捕告訴你: 你想申請什麼? PK 執照是 pk license 啊!\n");
    return 1;
  }
  message_vision ("$N向九省總巡捕申請了一張ＰＫ執照。\n", this_player());
  new(PK_LICENSE)->move(this_player());
  return 1;
}
