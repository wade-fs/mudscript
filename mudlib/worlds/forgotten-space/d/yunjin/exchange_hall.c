// /d/yunjin/exchange_hall.c
// 雲津仙集・三宗交割廳暨雲海票號 (Ch.84, Ch.90：顧蘭舟核驗實物倉單與準備金)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・三宗交割廳暨雲海票號");
    set_long("堂內不見浮誇的沉香氣，唯有一股淡淡的油墨與冷鐵味道。高大的紅木櫃檯上\n"
             "陳列著三宗物資交割回執木架與信用準備金核驗板，雲海票號女掌櫃顧蘭舟在此專司\n"
             "跨州匯兌、實物倉單抵押保書與延誤違約劃扣清算（十會會武核驗準備金暨擠兌稽核：audit wanbao）。\n"
             "向西退回【萬山商埠公所】。\n");

    set_exits(([
        "west": "/d/yunjin/public_office.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", YEL "高大紅木櫃檯打磨得極為光滑冰涼，竹簡與木質倉單牌碼放得稜角齊整。" NOR);
    set_smell("default", WHT "堂內只有淡淡油墨印泥、冷鐵櫃鎖與乾燥防潮松木匣的清冷氣味。" NOR);
    set_listen("default", HIY "算盤珠清脆利落的撥動聲、印章蓋上厚宣紙的沉穩頓響與商戶低聲核對帳目。" NOR);

    add_action_rule("settle", ([
        "targets": ({ "split_indemnity", "pledge_warehouse" }),
        "quest_verb": "settle",
        "quest_target_from_arg": 1,
        "usage_msg": "請選擇延誤貨單清算方案：settle split_indemnity（分批自賠）或 settle pledge_warehouse（倉單抵押）。",
        "sensory_msgs": ([
            "split_indemnity": HIY "你咬牙拆開備用銀匣按約補足分批違約款，堂內數位押貨掌櫃肅然起敬、當即加簽冬春長約！" NOR,
            "pledge_warehouse": CYN "你取出實物炭垛與雪松木倉單押入雲海票號銅櫃，顧蘭舟點頭放行展期交割憑證！" NOR
        ]),
        "exp_gain": 15
    ]));
    add_action_rule("seal", ([
        "targets": ({ "blind_bags", "customs_registry" }),
        "quest_verb": "seal",
        "quest_target_from_arg": 1,
        "usage_msg": "請選擇五方對帳副本保全方式：seal blind_bags（五袋防潮盲封）或 seal customs_registry（公所優先備案）。",
        "sensory_msgs": ([
            "blind_bags": HIG "五套防潮油布袋各自編號並交由五方代表聯簽盲封，鎖入雲海票號地庫銅匣。" NOR,
            "customs_registry": HIY "你當眾請羅九秤將五方對帳總目逐項登錄萬山公所官簿，任何單方皆無法再私下塗銷。" NOR
        ]),
        "exp_gain": 18
    ]));

    spawn_npc("/clone/npc/gu_lanzhou.c");
}

void init() {
    ::init();
    add_action("do_audit", "audit");
    add_action("do_yunjin_cargo", "cargo");
    add_action("do_yunjin_cargo", "跑商");
}

int do_yunjin_cargo(string arg) {
    object me = this_player();
    if (!me) return 0;
    object ws = load_object(WORLD_STATE_D);
    if (!ws) return 0;

    if (!arg || arg == "" || arg == "list" || arg == "行情") {
        write(ws->format_trade_board("yunjin"));
        return 1;
    }
    string sub = "";
    string cid = "";
    if (sscanf(arg, "%s %s", sub, cid) == 2 && (sub == "buy" || sub == "買")) {
        mapping bres = ws->buy_trade_cargo(me, cid, "yunjin");
        write(bres["msg"] + "\n");
        return 1;
    }
    if (arg == "sell" || arg == "賣") {
        mapping sres = ws->sell_trade_cargo(me, "yunjin");
        write(sres["msg"] + "\n");
        return 1;
    }
    write("用法：cargo list | cargo buy <貨號> | cargo sell\n");
    return 1;
}

int do_audit(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "wanbao" && arg != "reserves" && arg != "萬寶閣" && arg != "準備金") {
        notify_fail("你想稽核哪項帳冊？試試：audit wanbao\n");
        return 0;
    }
    message_vision("$N聯手羅九秤與顧蘭舟攤開近兩月異常匯兌總冊，揭破萬寶閣假造『越冬燃料預付款』\n"
                   "倉單私挪準備金一百八十萬靈石票炒作南境礦藥期貨，依法觸發《商埠危機處置律》\n"
                   "查封萬寶閣後庫七口「太清、丹鼎、天工」暗標黑鐵帳箱，並自賠退約保住泥途商棧！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "audit", "target": "wanbao" ]));
    }
    return 1;
}
