// clone/item/trade_cargo.c
// 因果跑商實體貨包 - 承載六縣與黑石鋪大宗特產跨區套利、運輸損耗與關卡稅率風險

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("封箱行商貨包");
    set_short(YEL "《行商專材貨包》" NOR);
    set_long("一捆用厚麻布與油紙緊緊扎實的地區特產貨包，上面蓋著起運縣市牙行的紅泥貨批印。\n");
    set_id(({ "trade_cargo", "cargo", "goods_pack", "貨包", "行商貨包" }));
    set("is_trade_cargo", 1);
    set("cargo_id", "panmu_timber");
    set("origin_hub", "panmu");
    set("buy_price", 35);
    set("cargo_condition", 100);
    set("tariff_flagged", 0);
    set("value", 35);
    set("weight", 4);
}

void setup_cargo(string cid, string cname, string orig, int bprice) {
    set_name(cname);
    set_short(YEL "《行商貨包：" + cname + "》" NOR);
    set_long(sprintf("一捆從【%s】採買發出的「%s」實體貨包，買入成本 %d 文，目前成色 %d%%，可運往他地牙行或商埠交割。\n",
        orig, cname, bprice, query("cargo_condition") ? query("cargo_condition") : 100));
    set_id(({ "trade_cargo", "cargo", cid, cname, "貨包" }));
    set("cargo_id", cid);
    set("origin_hub", orig);
    set("buy_price", bprice);
    set("cargo_condition", 100);
    set("tariff_flagged", 0);
    set("value", bprice);
}

int apply_transport_damage(int loss_pct, string reason) {
    int cond = query("cargo_condition");
    if (cond <= 0) cond = 100;
    cond -= loss_pct;
    if (cond < 50) cond = 50;
    set("cargo_condition", cond);
    set("hazard_note", reason ? reason : "路途潮濕受損");
    return cond;
}

void flag_tariff(string reason) {
    set("tariff_flagged", 1);
    set("tariff_note", reason ? reason : "無路引關卡加徵補稅");
}
