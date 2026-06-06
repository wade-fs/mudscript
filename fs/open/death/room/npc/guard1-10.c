//  guard1-10 make by pokai

inherit NPC;

void create()
{
	set_name("關卡守衛",({"guard"}));
        set("gender", "男性");
	set("age",500);
        set("long","
    一隻相貌醜惡的鬼卒守衛，你瞧他那副穿金帶銀的模樣，不禁懷疑一般的守衛
怎會這樣有錢？　難道...... 不如問問他怎樣通過(pass)這裡好了。\n");

        set("chat_chance", 1);
        set("chat_msg",({
        "關卡守衛用古怪的語調喝道：「你看什麼看啊！小心老子扁你！」\n",
 	"關卡守衛用斜眼瞄你，露出貪婪的笑容。\n",
        }));

        set("inquiry", ([
            "pass" : "沒聽說過賄賂(bribe)啊！難道要老子教你？\n",
        ]));

	setup();
}

int accept_fight(object me)
{
        command("say 你老師咧！去去去....連你老子都想扁！\n");
        return 0;
}
