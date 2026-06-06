// 有關於 npc 的種種設定, 請到 /doc/build/npc 去參考
//	manque_swordman.c		designed by dos  95'12
inherit NPC;


void create()
{
	set_name("失意劍客", ({ "manque swordman", "swordman"}) );
	set("long", "你看到一位失意劍客, 臉上透漏出悲哀
的神情. 你或許\可以問問他, 看看是否有
故事(story)可以聽. \n");

	// 年齡
	// 由於系統將會依年齡而計算出, 該怪物之天賦及基本狀態,
	// 故請務必設定怪物的年齡。
	set("age", 30);

	// 天賦, 請參考 help gift
	// set( "屬性", 數值 );		<-- 數值範圍: 10 - 30
	// 如果沒有設定, 將由年齡計算
	set("str",22);
	set("cor", 18);
	set("per", 27);

	// 狀態
	// 一般沒有特殊技能的怪物, 其戰鬥經驗(combat_exp)幾乎決定了怪物的強度。
	// set( "combat_exp", 數值 );
	// set( "score", 數值 );
	set("combat_exp", 3000);

	// 種族
	// 種族會影響攻擊方式, 請參考 /doc/build/npc 的第八項
	// 如果未指定種族, 系統將會自動選定人類。
	// 目前已知的有: 人類, 賽亞人, 妖魔, 野獸 
	set("race", "人類");

	// 性別
	// 依種族之不同, 有兩種系統: 1.男性, 女性。
	//                           2.雄性, 雌性, 中性。
	// 設定方式: set( "gender", "性別" );
	set( "gender", "男性");

	// 設定 npc 攻擊方式及受功擊部位。
	// set( "limbs", ({ "受功部位1", "受功部位2", ...}) );
	set("limbs", ({ "頭部", "身體", "手部", "腳跟", "喉嚨" }) );
	// set( "verbs", ({ "攻擊方式1", "攻擊方式2", ...}) );
//	set("verbs", ({"bite", "claw" }) );

	// 暗語
	// 我們可以在怪物上設定某些暗語, 使得當玩家詢問(ask)特定之
	// 關鍵字時, 怪物能自動做我們預設之動作。
	// 設定方式: set( "inquiry", ([
        //	          "暗語1" : "回應之語\n",
        //	          "暗語2" : (: this_object(), "呼叫副程式之名" :)
        //	        ]) );
	set("inquiry", ([
		"story"	:	"唉, 過去的事就不要再提了! \n",

		"故事" :	"我現在沒有心情說故事... \n",
	]) );

        // attitude npc 的戰鬥行為請參考 /doc/help/attitude
	set("attitude", "heroism");

        set("chat_chance", 6);
        set("chat_msg", ({
        }) );


        setup();
	carry_object("/open/main/obj/manque_shield.c")->wear();
	carry_object("/open/main/obj/manque_sword.c")->wield();
//	carry_object("/open/main/obj/sword_cloth.c")->wear();
}
