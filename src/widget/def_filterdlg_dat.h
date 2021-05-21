/*$
 Copyright (C) 2013-2021 Azel.

 This file is part of AzPainter.

 AzPainter is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 AzPainter is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
$*/

/***************************************
 * フィルタダイアログデータ
 ***************************************/

//プレビュータイプ
enum
{
	FDDAT_PREV_NONE,
	FDDAT_PREV_IN_DIALOG,
	FDDAT_PREV_CANVAS_COLOR,
	FDDAT_PREV_CANVAS_COMIC
};

//フラグ
enum
{
	FDDAT_F_RESET_BUTTON = 1<<3,	//リセットボタン
	FDDAT_F_GET_CANVAS_POS = 1<<4,	//キャンバス上で押された位置を取得
	FDDAT_F_SAVE_DATA = 1<<5		//値の保存
};

//ウィジェットタイプ
enum
{
	WG_BAR,
	WG_BAR_TYPE,
	WG_CHECK,
	WG_COMBO,
	WG_LABEL,
	WG_DEF_CLIPPING = 128,
	WG_DEF_LEVEL,
	WG_DEF_REPLACE_COL,
	WG_END = 255
};

//BAR_TYPE のタイプ
enum
{
	BAR_TYPE_IMGBITVAL	//イメージビット数分の値
};

#define VAL16(n)  (n >> 8) & 255,n & 255
#define BARWIDTH_DEF  0x01,0x18
#define PREVSIZE_DEF  0,220, 0,220

//文字列ID
enum
{
	TRID_BRIGHTNESS = 10,	//明度
	TRID_CONTRAST,		//コントラスト
	TRID_GAMMA,			//ガンマ値
	TRID_HUE,			//色相
	TRID_SATURATION,	//彩度
	TRID_THRESHOLD_VAL,	//しきい値
	TRID_TYPE,			//タイプ
	TRID_GRADATION,		//階調
	TRID_RADIUS,		//半径
	TRID_ANGLE,			//角度
	TRID_STRENGTH,		//強さ
	TRID_HELP_CANVASPOS,	//キャンバスクリックヘルプ
	TRID_HILIGHT,		//強調
	TRID_FREQUENCY,		//サイクル数
	TRID_SHARPNESS,		//鮮明さ
	TRID_COLOR,			//色
	TRID_SIZE,			//サイズ
	TRID_DENSITY,		//濃度
	TRID_ANTIALIAS,		//アンチエイリアス
	TRID_AMOUNT,		//量
	TRID_RAND_RADIUS,	//ランダム:半径
	TRID_RAND_DENSITY,	//ランダム:濃度
	TRID_DRAWPOINT_TYPE,	//描画点のタイプ
	TRID_THICKNESS,		//太さ
	TRID_THICKNESS_MIN,	//太さ最小
	TRID_THICKNESS_MAX,	//太さ最大
	TRID_INTERVAL_MIN,	//間隔最小
	TRID_INTERVAL_MAX,	//間隔最大
	TRID_HORZ_LINE,		//横線
	TRID_VERT_LINE,		//縦線
	TRID_COLUMN_WIDTH,	//横幅
	TRID_ROW_WIDTH,		//縦幅
	TRID_SAME_COLUMN_WIDTH,	//縦幅を横幅と同じにする
	TRID_USE_ADVCOLOR,	//平均色を使う
	TRID_ANGLE_R,		//角度R
	TRID_ANGLE_G,		//角度G
	TRID_ANGLE_B,		//角度B
	TRID_SAME_ANGLE_R,	//角度をすべて R と同じにする
	TRID_GRAYSCALE,		//グレイスケール
	TRID_APPLY_AMOUNT,	//適用量
	TRID_DISTANCE,		//距離
	TRID_REVERSE,		//反転
	TRID_LENGTH,		//長さ
	TRID_WIDTH,			//幅
	TRID_END_TO_LOOP,	//端はループ
	TRID_BACKGROUND,	//背景
	TRID_ZOOM,			//拡大縮小
	TRID_COUNT,			//回数
	TRID_CHECKEDLAYER_SRC,	//チェックレイヤをソースに
	TRID_CUT_SRCIMG,		//ソース画像を切り抜く
	TRID_SMOOTH,			//滑らかにする
	TRID_AMITONE_LINE,		//線数
	TRID_FIX_DENSITY,		//濃度固定
	TRID_BKGND_TO_WHITE,	//背景を白にする
	TRID_ASPECT_RATIO,		//縦横比
	TRID_DENSITY_COMIC,		//密度
	TRID_INTERVAL_RAND,		//間隔ランダム
	TRID_THICKNESS_RAND,	//太さランダム
	TRID_LENGTH_RAND,		//長さランダム
	TRID_WAVE_LENGTH,		//波の長さ
	TRID_TAIL_THICKNESS,	//抜きの太さ
	TRID_SIMPLE_PREVIEW,	//簡易プレビュー
	TRID_PREVIEW_RED,		//赤色でプレビュー

	TRID_THRESHOLD_DITHER_TYPE = 1000,	//2値化ディザタイプ
	TRID_DRAW_CLOUD_COLOR,		//雲模様の色
	TRID_DRAW_COLOR_LIST,		//描画の色 (描画色/背景色/黒/白)
	TRID_DRAWPOINT_TYPE_LIST,	//描画点のタイプ
	TRID_DRAWPOINT_COLOR_LIST,	//描画点の色
	TRID_DRAWPOINT_EDGETYPE_LIST,	//縁を点描画
	TRID_DIRECTION_TYPE_LIST,		//斜め/横/縦
	TRID_MEDIAN_TYPE_LIST,		//メディアンのタイプ
	TRID_WAVE_TYPE_LIST,		//波形のタイプ
	TRID_POLAR_TYPE_LIST,		//極座標タイプ
	TRID_BKGND_TYPE_LIST,		//透明/端の色/そのまま
	TRID_COMIC_DRAWTYPE		//漫画用描画のタイプ
};


//--------- カラー

//明度・コントラスト調整
static const uint8_t g_col_brightconst[] = {
	FDDAT_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR, TRID_BRIGHTNESS, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_BAR, TRID_CONTRAST, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_END
};

//ガンマ補正
static const uint8_t g_col_gamma[] = {
	FDDAT_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR, TRID_GAMMA, 11, BARWIDTH_DEF, VAL16(10), VAL16(400), VAL16(100), VAL16(100), 2,
	WG_END
};

//レベル補正
static const uint8_t g_col_level[] = {
	FDDAT_PREV_CANVAS_COLOR, WG_DEF_LEVEL, WG_END
};

//RGB補正
static const uint8_t g_col_rgb[] = {
	FDDAT_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR, 255,'R', 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_BAR, 255,'G', 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_BAR, 255,'B', 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_END
};

//HSV調整
static const uint8_t g_col_hsv[] = {
	FDDAT_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR, TRID_HUE, 6, BARWIDTH_DEF, VAL16(-180), VAL16(180),
	WG_BAR, TRID_SATURATION, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_BAR, TRID_BRIGHTNESS, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_END
};

//HSL調整
static const uint8_t g_col_hsl[] = {
	FDDAT_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR, 255,'H', 6, BARWIDTH_DEF, VAL16(-180), VAL16(180),
	WG_BAR, 255,'S', 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_BAR, 255,'L', 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_END
};

//2値化
static const uint8_t g_col_threshold[] = {
	FDDAT_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR_TYPE, TRID_THRESHOLD_VAL, 3, BARWIDTH_DEF, BAR_TYPE_IMGBITVAL,
	WG_END
};

//2値化(ディザ)
static const uint8_t g_col_threshold_dither[] = {
	FDDAT_PREV_CANVAS_COLOR,
	WG_COMBO, TRID_TYPE, 2, VAL16(TRID_THRESHOLD_DITHER_TYPE),
	WG_END
};

//ポスタリゼーション
static const uint8_t g_col_posterize[] = {
	FDDAT_PREV_CANVAS_COLOR,
	WG_BAR, TRID_GRADATION, 8, VAL16(200), VAL16(2), VAL16(64), VAL16(4),
	WG_END
};

//------- 色置換

//描画色置換
static const uint8_t g_col_replace_drawcol[] = {
	FDDAT_PREV_CANVAS_COLOR,
	WG_DEF_REPLACE_COL, WG_END,
};

//------- ぼかし

//ぼかし
static const uint8_t g_blur_blur[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_RADIUS, 6, VAL16(100), VAL16(1), VAL16(30),
	WG_DEF_CLIPPING,
	WG_END
};

//ガウスぼかし
static const uint8_t g_blur_gauss[] = {
	FDDAT_PREV_IN_DIALOG, VAL16(200), VAL16(200),
	WG_BAR, TRID_RADIUS, 6, VAL16(100), VAL16(1), VAL16(20),
	WG_DEF_CLIPPING,
	WG_END
};

//モーションブラー
static const uint8_t g_blur_motion[] = {
	FDDAT_PREV_IN_DIALOG, VAL16(200), VAL16(200),
	WG_BAR, TRID_RADIUS, 6, VAL16(100), VAL16(1), VAL16(20),
	WG_BAR, TRID_ANGLE, 6, VAL16(180), VAL16(-180), VAL16(180),
	WG_DEF_CLIPPING,
	WG_END
};

//放射状ぼかし
static const uint8_t g_blur_radial[] = {
	FDDAT_PREV_IN_DIALOG | FDDAT_F_GET_CANVAS_POS, VAL16(200), VAL16(200),
	WG_BAR, TRID_STRENGTH, 8, VAL16(120), VAL16(1), VAL16(50), VAL16(3),
	WG_DEF_CLIPPING,
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
	WG_END
};

//レンズぼかし
static const uint8_t g_blur_lens[] = {
	FDDAT_PREV_IN_DIALOG, VAL16(200), VAL16(200),
	WG_BAR, TRID_RADIUS, 8, VAL16(120), VAL16(1), VAL16(16), VAL16(3),
	WG_BAR, TRID_HILIGHT, 8, VAL16(120), VAL16(0), VAL16(150), VAL16(10),
	WG_DEF_CLIPPING,
	WG_END
};

//------- 描画

//雲模様
static const uint8_t g_draw_cloud[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_FREQUENCY, 8, VAL16(180), VAL16(2), VAL16(200), VAL16(7),
	WG_BAR, TRID_SHARPNESS, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(55),
	WG_BAR, TRID_CONTRAST, 8, VAL16(180), VAL16(0), VAL16(100), VAL16(25),
	WG_COMBO, TRID_COLOR, 2, VAL16(TRID_DRAW_CLOUD_COLOR),
	WG_END
};

//アミトーン
static const uint8_t g_draw_amitone[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_SIZE, 11, VAL16(180), VAL16(10), VAL16(4000), VAL16(100), VAL16(0), 1,
	WG_BAR, TRID_DENSITY, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(10),
	WG_BAR, TRID_ANGLE, 8, VAL16(180), VAL16(-180), VAL16(180), VAL16(45),
	WG_CHECK, TRID_ANTIALIAS, 1, 1,
	WG_COMBO, TRID_COLOR, 3, VAL16(TRID_DRAW_COLOR_LIST), 2,
	WG_END
};

//ランダム点描画
static const uint8_t g_draw_rndpoint[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_AMOUNT, 8, VAL16(180), VAL16(1), VAL16(512), VAL16(5),
	WG_BAR, TRID_RADIUS, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(2),
	WG_BAR, TRID_DENSITY, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(100),
	WG_BAR, TRID_RAND_RADIUS, 6, VAL16(180), VAL16(0), VAL16(100),
	WG_BAR, TRID_RAND_DENSITY, 6, VAL16(180), VAL16(0), VAL16(100),
	WG_COMBO, TRID_DRAWPOINT_TYPE, 2, VAL16(TRID_DRAWPOINT_TYPE_LIST),
	WG_COMBO, TRID_COLOR, 2, VAL16(TRID_DRAWPOINT_COLOR_LIST),
	WG_END
};

//縁に沿って点描画
static const uint8_t g_draw_edgepoint[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_CHECK, TRID_CHECKEDLAYER_SRC, 0,
	WG_COMBO, TRID_TYPE, 2, VAL16(TRID_DRAWPOINT_EDGETYPE_LIST),
	WG_BAR, TRID_RADIUS, 6, VAL16(160), VAL16(1), VAL16(100),
	WG_BAR, TRID_DENSITY, 8, VAL16(160), VAL16(1), VAL16(100), VAL16(100),
	WG_COMBO, TRID_DRAWPOINT_TYPE, 2, VAL16(TRID_DRAWPOINT_TYPE_LIST),
	WG_COMBO, TRID_COLOR, 2, VAL16(TRID_DRAWPOINT_COLOR_LIST),
	WG_END
};

//枠線
static const uint8_t g_draw_frame[] = {
	FDDAT_PREV_NONE,
	WG_BAR, TRID_THICKNESS, 6, VAL16(130), VAL16(1), VAL16(100),
	WG_COMBO, TRID_COLOR, 2, VAL16(TRID_DRAW_COLOR_LIST),
	WG_END
};

//水平線&垂直線
static const uint8_t g_draw_horzvert_line[] = {
	FDDAT_PREV_IN_DIALOG, VAL16(230), VAL16(230),
	WG_BAR, TRID_THICKNESS_MIN, 6, VAL16(180), VAL16(1), VAL16(100),
	WG_BAR, TRID_THICKNESS_MAX, 6, VAL16(180), VAL16(1), VAL16(100),
	WG_BAR, TRID_INTERVAL_MIN, 8, VAL16(180), VAL16(1), VAL16(400), VAL16(2),
	WG_BAR, TRID_INTERVAL_MAX, 8, VAL16(180), VAL16(1), VAL16(400), VAL16(2),
	WG_CHECK, TRID_HORZ_LINE, 1, 1,
	WG_CHECK, TRID_VERT_LINE, 0,
	WG_COMBO, TRID_COLOR, 2, VAL16(TRID_DRAW_COLOR_LIST),
	WG_END
};

//チェック柄
static const uint8_t g_draw_plaid[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_COLUMN_WIDTH, 8, VAL16(180), VAL16(2), VAL16(400), VAL16(5),
	WG_BAR, TRID_ROW_WIDTH, 8, VAL16(180), VAL16(2), VAL16(400), VAL16(5),
	WG_CHECK, TRID_SAME_COLUMN_WIDTH, 1, 1,
	WG_COMBO, TRID_COLOR, 2, VAL16(TRID_DRAW_COLOR_LIST),
	WG_END
};

//------- 漫画用

//網トーン生成
static const uint8_t g_comic_amitone_create[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_AMITONE_LINE, 11, VAL16(180), VAL16(10), VAL16(1600), VAL16(600), VAL16(0), 1,
	WG_BAR, TRID_DENSITY, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(10),
	WG_BAR, TRID_ANGLE, 8, VAL16(180), VAL16(-180), VAL16(180), VAL16(45),
	WG_COMBO, TRID_COLOR, 3, VAL16(TRID_DRAW_COLOR_LIST), 2,
	WG_CHECK, TRID_BKGND_TO_WHITE, 0,
	WG_END
};

//網トーン化
static const uint8_t g_comic_to_amitone[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_AMITONE_LINE, 11, VAL16(180), VAL16(10), VAL16(1600), VAL16(600), VAL16(0), 1,
	WG_BAR, TRID_ANGLE, 8, VAL16(180), VAL16(-180), VAL16(180), VAL16(45),
	WG_COMBO, TRID_COLOR, 3, VAL16(TRID_DRAW_COLOR_LIST), 2,
	WG_CHECK, TRID_BKGND_TO_WHITE, 0,
	WG_END
};

//砂目トーン化
static const uint8_t g_comic_sand_tone[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_FREQUENCY, 8, VAL16(180), VAL16(5), VAL16(200), VAL16(70),
	WG_CHECK, TRID_FIX_DENSITY, 0,
	WG_BAR, TRID_DENSITY, 8, VAL16(180), VAL16(1), VAL16(99), VAL16(50),
	WG_COMBO, TRID_COLOR, 3, VAL16(TRID_DRAW_COLOR_LIST), 2,
	WG_CHECK, TRID_BKGND_TO_WHITE, 0,
	WG_END
};

//集中線
static const uint8_t g_comic_concline[] = {
	FDDAT_PREV_CANVAS_COMIC | FDDAT_F_GET_CANVAS_POS | FDDAT_F_RESET_BUTTON | FDDAT_F_SAVE_DATA,
	WG_BAR, TRID_RADIUS, 12, VAL16(200), VAL16(10), VAL16(5000), VAL16(200), VAL16(0), 0, 'a',  //半径
	WG_BAR, TRID_ASPECT_RATIO, 12, VAL16(200), VAL16(-1000), VAL16(1000), VAL16(0), VAL16(0), 3, 'b',  //縦横比
	WG_BAR, TRID_DENSITY_COMIC, 12, VAL16(200), VAL16(2), VAL16(300), VAL16(15), VAL16(0), 0, 'c',    //密度
	WG_BAR, TRID_INTERVAL_RAND, 12, VAL16(200), VAL16(0), VAL16(99), VAL16(0), VAL16(0), 0, 'd',  //間隔
	WG_BAR, TRID_THICKNESS, 12, VAL16(200), VAL16(2), VAL16(1000), VAL16(25), VAL16(0), 1, 'e',   //太さ
	WG_BAR, TRID_THICKNESS_RAND, 12, VAL16(200), VAL16(0), VAL16(1000), VAL16(0), VAL16(0), 1, 'f',  //太さランダム
	WG_BAR, TRID_LENGTH, 12, VAL16(200), VAL16(1), VAL16(1000), VAL16(500), VAL16(0), 1, 'g', //長さ
	WG_BAR, TRID_LENGTH_RAND, 12, VAL16(200), VAL16(0), VAL16(1000), VAL16(200), VAL16(0), 1, 'h',  //長さランダム
	WG_COMBO, TRID_TYPE, 4, VAL16(TRID_COMIC_DRAWTYPE), 0, 'i',  //描画タイプ
	WG_CHECK, TRID_SIMPLE_PREVIEW, 2, 1, 'j',
	WG_CHECK, TRID_PREVIEW_RED, 2, 1, 'k',
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
	WG_END
};

//フラッシュ
static const uint8_t g_comic_flash[] = {
	FDDAT_PREV_CANVAS_COMIC | FDDAT_F_GET_CANVAS_POS | FDDAT_F_RESET_BUTTON | FDDAT_F_SAVE_DATA,
    WG_BAR, TRID_RADIUS, 12, VAL16(200), VAL16(10), VAL16(5000), VAL16(200), VAL16(0), 0, 'a',
    WG_BAR, TRID_ASPECT_RATIO, 12, VAL16(200), VAL16(-1000), VAL16(1000), VAL16(0), VAL16(0), 3, 'b',
    WG_BAR, TRID_DENSITY_COMIC, 12, VAL16(200), VAL16(2), VAL16(300), VAL16(100), VAL16(0), 0, 'c',
    WG_BAR, TRID_INTERVAL_RAND, 12, VAL16(200), VAL16(0), VAL16(99), VAL16(20), VAL16(0), 0, 'd',
    WG_BAR, TRID_THICKNESS, 12, VAL16(200), VAL16(2), VAL16(1000), VAL16(40), VAL16(0), 1, 'e',
    WG_BAR, TRID_THICKNESS_RAND, 12, VAL16(200), VAL16(0), VAL16(1000), VAL16(30), VAL16(0), 1, 'f',
    WG_BAR, TRID_LENGTH, 12, VAL16(200), VAL16(1), VAL16(1000), VAL16(350), VAL16(0), 1, 'g',
    WG_BAR, TRID_LENGTH_RAND, 12, VAL16(200), VAL16(0), VAL16(1000), VAL16(200), VAL16(0), 1, 'h',
    WG_COMBO, TRID_TYPE, 4, VAL16(TRID_COMIC_DRAWTYPE), 0, 'i',
    WG_CHECK, TRID_SIMPLE_PREVIEW, 2, 1, 'j',
    WG_CHECK, TRID_PREVIEW_RED, 2, 1, 'k',
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
    WG_END
};

//ベタフラッシュ
static const uint8_t g_comic_popupflash[] = {
	FDDAT_PREV_CANVAS_COMIC | FDDAT_F_GET_CANVAS_POS | FDDAT_F_RESET_BUTTON | FDDAT_F_SAVE_DATA,
    WG_BAR, TRID_RADIUS, 12, VAL16(200), VAL16(10), VAL16(5000), VAL16(130), VAL16(0), 0, 'a',
    WG_BAR, TRID_ASPECT_RATIO, 12, VAL16(200), VAL16(-1000), VAL16(1000), VAL16(0), VAL16(0), 3, 'b',
    WG_BAR, TRID_DENSITY, 12, VAL16(200), VAL16(2), VAL16(300), VAL16(80), VAL16(0), 0, 'c',
    WG_BAR, TRID_INTERVAL_RAND, 12, VAL16(200), VAL16(0), VAL16(99), VAL16(20), VAL16(0), 0, 'd',
    WG_BAR, TRID_THICKNESS, 12, VAL16(200), VAL16(2), VAL16(1000), VAL16(30), VAL16(0), 1, 'e',
    WG_BAR, TRID_THICKNESS_RAND, 12, VAL16(200), VAL16(0), VAL16(1000), VAL16(20), VAL16(0), 1, 'f',
    WG_BAR, TRID_LENGTH, 12, VAL16(200), VAL16(1), VAL16(1000), VAL16(250), VAL16(0), 1, 'g',
    WG_BAR, TRID_LENGTH_RAND, 12, VAL16(200), VAL16(0), VAL16(1000), VAL16(300), VAL16(0), 1, 'h',
    WG_COMBO, TRID_TYPE, 4, VAL16(TRID_COMIC_DRAWTYPE), 0, 'i',
    WG_CHECK, TRID_SIMPLE_PREVIEW, 2, 1, 'j',
    WG_CHECK, TRID_PREVIEW_RED, 2, 1, 'k',
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
    WG_END
};

//ウニフラッシュ
static const uint8_t g_comic_uniflash[] = {
	FDDAT_PREV_CANVAS_COMIC | FDDAT_F_GET_CANVAS_POS | FDDAT_F_RESET_BUTTON | FDDAT_F_SAVE_DATA,
    WG_BAR, TRID_RADIUS, 12, VAL16(200), VAL16(10), VAL16(5000), VAL16(160), VAL16(0), 0, 'a',
    WG_BAR, TRID_ASPECT_RATIO, 12, VAL16(200), VAL16(-1000), VAL16(1000), VAL16(0), VAL16(0), 3, 'b',
    WG_BAR, TRID_DENSITY_COMIC, 12, VAL16(200), VAL16(2), VAL16(300), VAL16(110), VAL16(0), 0, 'c',
    WG_BAR, TRID_INTERVAL_RAND, 12, VAL16(200), VAL16(0), VAL16(99), VAL16(0), VAL16(0), 0, 'd',
    WG_BAR, TRID_THICKNESS, 12, VAL16(200), VAL16(2), VAL16(1000), VAL16(30), VAL16(0), 1, 'e',
    WG_BAR, TRID_THICKNESS_RAND, 12, VAL16(200), VAL16(0), VAL16(1000), VAL16(0), VAL16(0), 1, 'f',
    WG_BAR, TRID_LENGTH, 12, VAL16(200), VAL16(1), VAL16(1000), VAL16(300), VAL16(0), 1, 'g',
    WG_BAR, TRID_LENGTH_RAND, 12, VAL16(200), VAL16(0), VAL16(1000), VAL16(0), VAL16(0), 1, 'h',
    WG_COMBO, TRID_TYPE, 4, VAL16(TRID_COMIC_DRAWTYPE), 0, 'i',
    WG_CHECK, TRID_SIMPLE_PREVIEW, 2, 1, 'j',
    WG_CHECK, TRID_PREVIEW_RED, 2, 1, 'k',
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
    WG_END
};

//ウニフラッシュ(波)
static const uint8_t g_comic_uniflash_wave[] = {
	FDDAT_PREV_CANVAS_COMIC | FDDAT_F_GET_CANVAS_POS | FDDAT_F_RESET_BUTTON | FDDAT_F_SAVE_DATA,
    WG_BAR, TRID_RADIUS, 12, VAL16(200), VAL16(10), VAL16(5000), VAL16(160), VAL16(0), 0, 'a',
    WG_BAR, TRID_ASPECT_RATIO, 12, VAL16(200), VAL16(-1000), VAL16(1000), VAL16(0), VAL16(0), 3, 'b',
    WG_BAR, TRID_DENSITY, 12, VAL16(200), VAL16(2), VAL16(300), VAL16(30), VAL16(0), 0, 'c',
    WG_BAR, TRID_WAVE_LENGTH, 12, VAL16(200), VAL16(1), VAL16(1000), VAL16(200), VAL16(0), 1, 'd', //波の長さ
    WG_BAR, TRID_THICKNESS, 12, VAL16(200), VAL16(2), VAL16(1000), VAL16(15), VAL16(0), 1, 'e',
    WG_BAR, TRID_LENGTH, 12, VAL16(200), VAL16(1), VAL16(1000), VAL16(300), VAL16(0), 1, 'f',
    WG_BAR, TRID_TAIL_THICKNESS, 12, VAL16(200), VAL16(0), VAL16(100), VAL16(0), VAL16(0), 0, 'g', //抜きの太さ
    WG_COMBO, TRID_TYPE, 4, VAL16(TRID_COMIC_DRAWTYPE), 0, 'h',
    WG_CHECK, TRID_SIMPLE_PREVIEW, 2, 1, 'i',
    WG_CHECK, TRID_PREVIEW_RED, 2, 1, 'j',
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
    WG_END
};

//------- ピクセレート

//モザイク
static const uint8_t g_pix_mozaic[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_SIZE, 6, VAL16(120), VAL16(2), VAL16(100),
	WG_DEF_CLIPPING,
	WG_END
};

//水晶
static const uint8_t g_pix_crystal[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_SIZE, 6, VAL16(150), VAL16(5), VAL16(200),
	WG_CHECK, TRID_USE_ADVCOLOR, 0,
	WG_DEF_CLIPPING,
	WG_END
};

//ハーフトーン
static const uint8_t g_pix_halftone[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_SIZE, 11, VAL16(180), VAL16(10), VAL16(2000), VAL16(50), VAL16(0), 1,
	WG_BAR, TRID_ANGLE_R, 8, VAL16(180), VAL16(-180), VAL16(180), VAL16(15),
	WG_BAR, TRID_ANGLE_G, 8, VAL16(180), VAL16(-180), VAL16(180), VAL16(75),
	WG_BAR, TRID_ANGLE_B, 6, VAL16(180), VAL16(-180), VAL16(180),
	WG_CHECK, TRID_SAME_ANGLE_R, 0,
	WG_CHECK, TRID_ANTIALIAS, 1, 1,
	WG_CHECK, TRID_GRAYSCALE, 0,
	WG_END
};

//------ 輪郭

//シャープ
static const uint8_t g_edge_sharp[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_STRENGTH, 8, VAL16(120), VAL16(1), VAL16(50), VAL16(3),
	WG_END
};

//アンシャープマスク
static const uint8_t g_edge_unsharpmask[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_RADIUS, 8, VAL16(180), VAL16(1), VAL16(20), VAL16(1),
	WG_BAR, TRID_STRENGTH, 8, VAL16(180), VAL16(1), VAL16(300), VAL16(50),
	WG_DEF_CLIPPING,
	WG_END
};

//ハイパス
static const uint8_t g_edge_highpass[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_RADIUS, 6, VAL16(100), VAL16(1), VAL16(20),
	WG_DEF_CLIPPING,
	WG_END
};

//------ 効果

//グロ―
static const uint8_t g_eff_glow[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_BRIGHTNESS, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(20),
	WG_BAR, TRID_RADIUS, 8, VAL16(180), VAL16(1), VAL16(20), VAL16(3),
	WG_BAR, TRID_APPLY_AMOUNT, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(60),
	WG_DEF_CLIPPING,
	WG_END
};

//RGBずらし
static const uint8_t g_eff_rgbshift[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_COMBO, TRID_TYPE, 2, VAL16(TRID_DIRECTION_TYPE_LIST),
	WG_BAR, TRID_DISTANCE, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(3),
	WG_DEF_CLIPPING,
	WG_END
};

//油絵風
static const uint8_t g_eff_oilpaint[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_RADIUS, 8, VAL16(100), VAL16(1), VAL16(8), VAL16(2),
	WG_DEF_CLIPPING,
	WG_END
};

//エンボス
static const uint8_t g_eff_emboss[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_STRENGTH, 6, VAL16(100), VAL16(1), VAL16(16),
	WG_COMBO, TRID_TYPE, 2, VAL16(TRID_DIRECTION_TYPE_LIST),
	WG_CHECK, TRID_REVERSE, 0,
	WG_CHECK, TRID_GRAYSCALE, 1, 1,
	WG_DEF_CLIPPING,
	WG_END
};

//ノイズ
static const uint8_t g_eff_noise[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_AMOUNT, 8, VAL16(160), VAL16(1), VAL16(100), VAL16(6),
	WG_CHECK, TRID_GRAYSCALE, 1, 1,
	WG_END
};

//拡散
static const uint8_t g_eff_diffusion[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_DISTANCE, 6, VAL16(160), VAL16(1), VAL16(50),
	WG_DEF_CLIPPING,
	WG_END
};

//ひっかき
static const uint8_t g_eff_scratch[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_LENGTH, 8, VAL16(180), VAL16(2), VAL16(50), VAL16(10),
	WG_BAR, TRID_ANGLE, 8, VAL16(180), VAL16(-180), VAL16(180), VAL16(45),
	WG_DEF_CLIPPING,
	WG_END
};

//メディアン
static const uint8_t g_eff_median[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_RADIUS, 6, VAL16(50), VAL16(1), VAL16(3),
	WG_COMBO, TRID_TYPE, 3, VAL16(TRID_MEDIAN_TYPE_LIST), 1,
	WG_DEF_CLIPPING,
	WG_END
};

//ぶれ
static const uint8_t g_eff_blurring[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_DISTANCE, 8, VAL16(120), VAL16(1), VAL16(60), VAL16(4),
	WG_DEF_CLIPPING,
	WG_END
};

//----------- 変形

//波形
static const uint8_t g_trans_wave[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_AMOUNT, 8, VAL16(180), VAL16(1), VAL16(50), VAL16(10),
	WG_BAR, TRID_WIDTH, 11, VAL16(180), VAL16(1), VAL16(500), VAL16(40), VAL16(0), 1,
	WG_COMBO, TRID_TYPE, 3, VAL16(TRID_WAVE_TYPE_LIST), 2,
	WG_DEF_CLIPPING,
	WG_CHECK, TRID_END_TO_LOOP, 0,
	WG_END
};

//波紋
static const uint8_t g_trans_ripple[] = {
	FDDAT_PREV_IN_DIALOG | FDDAT_F_GET_CANVAS_POS, PREVSIZE_DEF,
	WG_BAR, TRID_FREQUENCY, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(17),
	WG_BAR, TRID_AMOUNT, 8, VAL16(180), VAL16(1), VAL16(200), VAL16(50),
	WG_DEF_CLIPPING,
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
	WG_END
};

//極座標
static const uint8_t g_trans_polar[] = {
	FDDAT_PREV_NONE,
	WG_COMBO, TRID_TYPE, 2, VAL16(TRID_POLAR_TYPE_LIST),
	WG_COMBO, TRID_BACKGROUND, 2, VAL16(TRID_BKGND_TYPE_LIST),
	WG_END
};

//放射状ずらし
static const uint8_t g_trans_radial_shift[] = {
	FDDAT_PREV_IN_DIALOG | FDDAT_F_GET_CANVAS_POS, PREVSIZE_DEF,
	WG_BAR, TRID_LENGTH, 8, VAL16(180), VAL16(1), VAL16(150), VAL16(10),
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
	WG_END
};

//渦巻き
static const uint8_t g_trans_swirl[] = {
	FDDAT_PREV_IN_DIALOG | FDDAT_F_GET_CANVAS_POS, PREVSIZE_DEF,
	WG_BAR, TRID_AMOUNT, 8, VAL16(180), VAL16(1), VAL16(200), VAL16(20),
	WG_BAR, TRID_ZOOM, 11, VAL16(180), VAL16(1), VAL16(300), VAL16(100), VAL16(100), 2,
	WG_COMBO, TRID_BACKGROUND, 3, VAL16(TRID_BKGND_TYPE_LIST), 1,
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
	WG_END
};

//---------- ほか

//アンチエイリアシング
static const uint8_t g_other_antialiasing[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_STRENGTH, 8, VAL16(120), VAL16(1), VAL16(100), VAL16(80),
	WG_END
};

//縁取り
static const uint8_t g_other_hemming[] = {
	FDDAT_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_COUNT, 6, VAL16(120), VAL16(1), VAL16(20),
	WG_COMBO, TRID_COLOR, 2, VAL16(TRID_DRAW_COLOR_LIST),
	WG_CHECK, TRID_CHECKEDLAYER_SRC, 0,
	WG_CHECK, TRID_CUT_SRCIMG, 0,
	WG_END
};

//立体枠
static const uint8_t g_other_3dframe[] = {
	FDDAT_PREV_NONE,
	WG_BAR, TRID_WIDTH, 8, VAL16(100), VAL16(1), VAL16(100), VAL16(6),
	WG_CHECK, TRID_SMOOTH, 0,
	WG_CHECK, TRID_REVERSE, 0,
	WG_END
};

//シフト
static const uint8_t g_other_shift[] = {
	FDDAT_PREV_NONE,
	WG_BAR, 255,'X', 6, VAL16(280), VAL16(-1000), VAL16(1000),
	WG_BAR, 255,'Y', 6, VAL16(280), VAL16(-1000), VAL16(1000),
	WG_END
};

