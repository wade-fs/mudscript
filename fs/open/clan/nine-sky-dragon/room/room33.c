inherit ROOM;
void create() {
	set( "short", "再出發" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"amount5"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount7"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10527 );
	set( "exits", ([
		"south"     : "/open/clan/nine-sky-dragon/room/room26",
	]) );
	set( "long", @LONG
風大雨大太陽大 誰卡大聲 誰就贏 不管這條路有多歹行
攏不驚 天大地大 我雄大 歹人看到阮嘛皮皮剉
咱是認份快樂少爺 笑哈哈 再出發 再出發吧
妳是願ㄟ第一名 天公就疼這款命 嘎甘苦當作跳恰恰
嗯免驚 嗯免驚啦 咱是勇敢的小飛俠 帶著鋼盔嘎伊拼
人講沒行未出名 我有信心打不痛 我有認真做人看
不願浪費青春生命 壞名聲 我有姑娘咧愛我 我有幸福咧作伴
我要給她日子過得快活 惜命命 再出發 再出發吧
幫我擦汗揮著花 不管風雨這呢大 為得將來馬得走
要出發 要出發啦 幫我鞋子 擦亮它 那無實力脈臭彈
有影卡來這嗆聲 再出發 再出發啦 要拿冠軍第一名
天公就疼這款命 嘎甘苦當作跳恰恰 嗯免驚 嗯免驚啦
你是勇敢的小飛俠 帶著鋼盔嘎伊拼 人講沒行未出名
風大雨大太陽大 誰卡大聲 誰就贏 不管這條路有多歹行
攏不驚 天大地大 我雄大 歹人看到阮嘛皮皮剉
咱是認份快樂少爺 笑哈哈 我有信心打不痛 我有認真做人看
不願浪費青春生命 壞名聲 天大地大 我雄大
歹人看到阮嘛皮皮剉 咱是認份快樂少爺 笑哈哈
我有姑娘咧愛我 我有幸福咧作伴 我要給她日子過得快活
惜命命 風大雨大太陽大 誰卡大聲 誰就贏
不管這條路有多歹行 攏不驚

LONG);
	setup();
	replace_program(ROOM);
}
