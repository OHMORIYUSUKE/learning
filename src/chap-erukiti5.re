= 生成AIを活用する

//flushright{
@erukiti
//}

これまでの章では「学び」自体を徹底的に深掘りしてきた。この章では学びへの生成AI活用について語りたい@<fn>{erukiti-生成AIの学びへの活用}。

//footnote[erukiti-生成AIの学びへの活用][この記事を書いたきっかけは「（AIエンジニアとして）何かおすすめツールはありますか？」と聞かれたことである。]

== 生成AIとは

生成AIとは「生成するAI」である。馬鹿馬鹿しい定義だが、生成AIは研究・開発における専門用語でもなんでもなくて、単なるマーケティング用語だ。生成AIとはその程度の情報量しかない薄っぺらい言葉にすぎないが、使い勝手の良い言葉でもある。

筆者はAIエンジニアである。主に大規模言語モデル（以後、Large Language Modelの略でLLMと書く）を取り扱っている。LLMは文字列を入れたら、それに応じた最もそれらしい文字列を返してくれる魔法の技術くらいに考えればいい。

ChatGPTがLLM活用の代表的な事例だ。ソフトウェア技術者ならGitHub Copilotを使っているだろうか。あれもLLMを活用したものである。

生成AIは主に、アプリケーション・サービスとして提供されている。プロ向けにAPIという形でも提供されているため、学びを深めたい読者はAPIを触ってみてもいいだろう@<fn>{erukiti-localllm}。

//footnote[erukiti-localllm][さらにプロ向けの存在として、ローカルマシンでも動くローカルLLMというものもある。HuggingFaceという機械学習に特化したGitHubのようなサイトで、LLMの中身（学習されたデータ）がオープンで配布されている。これとオープンソースのLLMソフトを組み合わせると、自宅やクラウド上で好きなだけ使えるLLMになる。興味がある人は「ローカルLLM」「ollama」「LM Studio」「llama.cpp」などを調べるといいだろう。]

生成AIとしてマーケティングされているアプリケーション・サービスで、学びに活用出来そうなものを紹介していこう。

なお、筆者の個人的なおすすめは以下の通りだ。

 * 対話型AIならAnthropic社のClaude Professional Plan
 * ソフトウェア技術者ならGitHub Copilot
 * 検索エンジンの代わりに使うならperpelxity.ai
 * ドキュメントを元にあれこれ学びを深めるならNotebookLM

== 対話型AI

OpenAI社のChatGPT（チャットGPT）は対話型AIと呼ぶべきサービスである。同様のものにはAnthropic社（アンスロピック）のClaude（クロード）やGoogle社のGemini（ジェミニ）がある。

対話型AIは、対話、チャットによって、LLMに返答してもらうアプリケーションだ。利用者は何かしらの指示を出す。「学びについて教えて」「学びのプロセスについて詳細に掘り下げてみて」のような指示で、こういう指示のことをプロンプトという。

LLMや対話型AIの一番の特徴は、汎用性にある@<fn>{erukiti-llm}。
//footnote[erukiti-llm][旧来のAIと呼ばれる技術はどうしてもやれることが限定的だったが、LLMはあらゆることをこなせるポテンシャルがある。まだまだ人間の知的活動のすべてを奪えるものではないが、人類史上でも類を見ないスピードで進化し続けているため、数年以内に人間と同等の汎用性能といわれるAGIに到達する確率は高いとされている。]

プロンプトの与え方一つで、返答内容が千差万別に変わるというのが、対話型AIの強みであり、弱みでもある。強みはプロンプトの与え方さえマスターすれば汎用的に色々なことをこなせるということ。弱みは、プロンプトの与え方を間違えると、とてもイライラさせられることだ。

このプロンプトそのものがエンジニアリングの対象であるため、プロンプトエンジニアリングというものもある。

もう一つ重要なこととしてLLMという性質上の向き不向きもある。LLMはたとえばOpenAI社がアクセスを許可されている範囲の世界をある時点で切り取ったものなので、知識は最新のものではないし、学習の偏りもある。LLMは言葉を処理する能力が極めて高いが、知識は不完全なのだ。

学習素材が十分あるものは、つまりウェブ上に公開されている情報が多いジャンルのもの、たとえばTypeScriptやPythonの情報であれば知識の正しさはある程度あるだろう。これがマイナーなプログラム言語のことになってくると途端に正しさが失われる。

つまり対話型AIの知識を無条件で信用してはならない。

=== プロンプト

本書は学びの本なので、あまり踏み込んだ内容にすべきではないが、プロンプトは、LLMや対話型AIを使う上で欠かせないため、軽く説明をしよう。

プロンプトにおける一番重要な考え方は絞り込みである。検索エンジン活用と同じようなものだ@<fn>{erukiti-prompt}。汎用技術なのだから文脈を限定しないと、利用者の望むと答えを返さない可能性は高い。

//footnote[erukiti-prompt][プロンプトエンジニアリングとしてのコツは、最初は雑なプロンプトを投げて、どこまで指示を追加したらより適切な返答をしてくれるかを絞り込んでいく、という検索エンジンの活用テクニックに似たところがある。]

「学びについて教えて」と指示を出すと概略をつかむための一般論が帰ってくる。あなたは何を知りたいのだろうか？学びの定義か、学びのプロセスか、学びのコツか。検索エンジンを活用するのと同じように絞り込むと、少しずつあなたの知りたいことに近づくはずだ。

検索エンジンと違うのは、より詳細で自然な指示を追加出来る点だ。「学びのコツについて、中学生の情報の授業で役立つように、教えて」というような指示は、旧来の検索エンジンではできない。

ここまでを理解できれば、プロンプトに対する知識としては十分だ。インターネットにはうろんなプロンプトテクニックと称したものが出回ってるがそれらのほとんどは意味がない。ある時点では有効だったかもしれないが、最先端のLLMにとっては不要なものとなっていることが多い。

LLMも対話型AIも、なるべくプロンプトエンジニアリングが不要な方向に進化しているのだ。多くのユースケースではこう答えた方がいいようにアップデートし続けている。汎用技術であろうとする点と些かの矛盾を抱えているため、ときどきとんでもない会話をすることもある点には気をつけなければならない。

=== ChatGPT, Claude, Gemini

ChatGPTは、2024年12月6日時点では gpt-4o/gpt-4o-mini/o1/o1-mini/o1-pro などのモデル（LLMのこと）を使うことができる。これらのモデルはそれぞれ性能や応答速度が違う。

 * gpt-4oは標準的な最先端モデルである。賢いが応答が少し遅い
 * gpt-4o-miniは小さな最先端モデルである。gpt-4oよりは明らかに馬鹿だが、応答は早い
 * o1は実験的な最先端モデルである。gpt-4oと比べて遙かに思慮深いが計算コストはかかる。原稿執筆時点では世界で2番目に賢い
 * o1-proも実験的な最先端モデルである。原稿執筆時点では世界で最も賢い
 * o1-miniも実験的な最先端モデルである。gpt-4oとo1の中間のような存在である

ChatGPTやClaudeやGeminiをウェブ上で普通にアプリとして使う分には、どのモデルを選んだとしても、最先端モデル@<fn>{erukiti-frontiermodel}なのだ。

//footnote[erukiti-frontiermodel][最先端モデルとは、最低でも1兆円以上のハードウェアと、原子力発電所を専用に建造したくなるほどの莫大な電力消費と、世界のトップの中のトップの技術者を数百人以上費やして、開発されている、文字通りの最先端モデルである。最先端モデルを開発できる企業は2024年時点ではアメリカにしかない。二番手グループであれば、カナダ、フランス、中国、イギリスなどにも存在してる。日本もせめて二番手グループには入ってほしいものだ。]

無料でChatGPTを使っていると、モデル選択ができずにgpt-4o-miniに該当するモデルしか使えない。要するに無料ユーザーはとても馬鹿なモデルしか使えないのだ。

有料プランにも二種類ある。ChatGPT PlusとChatGPT Proだ。

ChatGPT Plusではgpt-4o・gpt-4o-mini・o1・o1-miniが利用できる。この中でo1は強い利用制限がかかっていて、12/6現時点では一週間のリクエスト数は50に限定されている。つまりお試しでo1が使えるという状況だ。月額＄20（日本円だと3000円くらい）だ。

ChatGPT Proは全部のモデルをほぼ無制限に使える。他にも色々と追加機能が登場している@<fn>{erukiti-chatgpt-pro}。月額＄200（日本円だと3万円くらい）だ。

//footnote[erukiti-chatgpt-pro][このような書き方をしているのは、12/6以後12日間に渡って、OpenAI社が新機能を相次いで発表するというスタイルを取っているため原稿の締め切りまでに全容を明らかにできないからだ。]

ライバルのClaudeも同様である。

 * 3.5-sonnet（ソネット）は極めて賢い最先端モデルである。日本語を扱うなら間違いなくトップ性能。応答速度はgpt-4oと同じようなもの
 * 3.5-haiku（ハイク）は賢い最先端モデルである。sonnetよりは劣るがgpt-4oにも負けない。応答速度はsonnetより速い
 * 3-haikuは小さな最先端モデルである。賢さも応答速度もgpt-4o-miniと似たようなものだと思えばいい

少しややこしいのは、gpt-4oに該当する3.5-sonnetと、gpt-4o-miniに該当する3-haikuの間に、中間的な性能である3.5-haikuが存在している。

Claudeの無料版も3-haikuに該当するモデルが使われている。

Claudeの有料版は2024年12月6日時点では、Professional Planがある。$20で、3.5-sonnetをほぼ使い放題というものだ。

つまり何が言いたいかというと、無料ユーザーは馬鹿なモデルしか使えないので、学びに活用しようと思うと圧倒的に力不足なのだ。絶対に後悔するので無料モデルなら使わない方がマシだと思った方がいい。ChatGPTを使えないという人の大半は無料モデルしか使っていない上、プロンプトの基本を知らないので、活用ができていないのだ。

有料プランであるChatGPT PlusやClaude Professional planは、両方とも毎月＄20、つまり日本円だと3000円くらいかかるので金がかかるが、その分とても賢い。もちろん、ChatGPT Proの＄200を支払う覚悟があればさらに賢いモデルにアクセスできる。

無料版は高校生か大学入ったけど頭の悪い子くらいの性能だが、有料版はトップレベルの大学院生くらいだと思っていい。特にClaudeの場合はだ。ChatGPTでgot-4oを使う限りそこまで頭は良くないが大学生〜ぎりぎり大学院生くらいだ。o1やo1-proに至ってはその遙か上だ。筆者はまだo1とo1-proを評価できていないが、それよりも劣るo1-previewという先行公開版だけでも、他のモデルとは異質の賢さ、思慮深さを感じ取っていた。

筆者は生成AIの専門家であるためChatGPT PlusとClaude Professional Planともに契約しているが、普通の人はどちらかを契約するといいだろう。どちらも一長一短だ。軍拡競争としか表現できないような競争を続けている両社@<fn>{erukiti-bigtech-war}なので、性能も実装してる機能も、極めて頻繁にアップデートが入ってしまうため、長期的に見てどちらが良いと言えないのだ。

//footnote[erukiti-bigtech-war][たとえばビッグテック各社（Google,Microsoft,Meta,Amazon）は技術開発に毎年ものすごい予算をかけ、ハードウェア・インフラに数兆円規模の投資をしている。ビッグテックの資金が流れ込んでいるOpenAIやAnthropicはインフラへの投資金額こそ低いが、札束を燃やして最先端モデルの開発と運用をしている。これらの競争が続くと、近未来SFで指摘されてきた一企業が国家を凌駕するのも時間の問題だ。人間を超える知性を持つAIを一企業が完全に所有するのだ。当然それを持たない存在すべてが対抗できないことを意味する。これは世界で始まった本当の経済戦争だ。]

さて、ここまでに述べた評価は2024年12月初め時点のものに過ぎないことを留意してほしい。2025年半ばくらいには細かい性能は変わっているだろう。ただし無料版はあきれるほど馬鹿なので有料版を使うべきという原則は絶対に何があっても変わらない@<fn>{erukiti-proplan}。そしておそらくClaudeの方が日本語性能は高いという傾向は2025年も続くはずだ。

//footnote[erukiti-proplan][gpt-4o-miniや3-haikuは、比較的軽量で馬鹿で速いモデルだが、それでもこれらを維持するのには考えたくもないほど莫大な費用がかかるのだ。いわゆるビッグテックの金を毎年燃やし続けているから維持できているに過ぎない。これを無料で使えること自体がおかしいレベルである。無料版は性能を抑えて、有料版に誘導したいというのが経済的な合理性である。フリーミアムモデルという、コンピュータの歴史において何度も見かけた光景やつだ。]

ここまでGoogleのGeminiを取り上げてこなかったのには理由がある。Geminiには、LLM・対話型AIにおける重大な欠陥である、ハルシネーションが生じやすいという問題がつきまとっていた。ハルシネーションは本当は存在しないものをそれっぽく答えるものだ。もちろんChatGPTやClaudeにも同じ問題はあるが、生じる可能性はより低い。

もちろんGeminiも、ChatGPTやClaudeと争うトップレベルの最先端モデルであり、最近は改善しているが、そういう過去があったので手放しでおすすめすづらい。

なお、プロンプトエンジニアリングをちゃんとしたうえで専門家としてAPIで触るならGeminiシリーズも本当に素晴らしい。2025年の間には一般向けにも手放しでおすすめできるようになっていると筆者は期待している。

=== 対話型AIに文章を書かせてみる

実際にClaude Professionalで問答をしてみよう。まず簡単に「学びについて教えて」と投げてみた。

なお、この目的においてはChatGPTよりもClaudeの方が圧倒的に適している。Claude 3 Sonnetが登場して以来、日本語の文章を書かせるというタスクにおいてはChatGPTは圧倒的にClaude Sonnetに負けていて、その傾向は3.5 Sonnetが登場した事でさらに進んでいる。日本語の文章を読み書きする点に特化するなら筆者としてはClaudeをおすすめしたい。

//emlist[Claude Sonnetの返答]{
学びとは人生において非常に重要なプロセスですね。効果的な学習には、以下のような要素が含まれます:

 1. 主体性と目的意識を持つこと - 何のために学ぶのか、どんな成長を目指すのかを明確にすると、モチベーションが保ちやすくなります。
 2. 実践と振り返りのサイクル - 知識を得るだけでなく、実践して、その結果を振り返ることで、より深い理解が得られます。
 3. 多角的なアプローチ - 一つの事柄でも、異なる視点から学ぶことで、より立体的な理解が可能になります。
 4. 継続的な取り組み - 短期的な詰め込みよりも、日々の少しずつの積み重ねの方が、長期的な成長につながります。
 5. 周囲との学び合い - 他者との対話や意見交換を通じて、自分一人では気づかなかった視点を得られます。

具体的にどのような分野や目的での学びに興味をお持ちですか？そうすれば、より具体的なアドバイスができるかもしれません。
//}

このような返答となる。優秀な回答ではあるが、一般論を語っているにすぎない。なお、この程度の会話であれば無料版ChatGPTでも似たような返答をしてくる。

たとえば、学びについて本を書きたいと思ったらどうするか？今度は「学びについて本の原稿を書こうと思う。どういう構成が考えられるか？」という指示を投げてみた。

//emlist[Claude Sonnetの返答]{
学びに関する本の構成について、以下のような案を提案させていただきます：

序章: なぜ今、学びが重要なのか
- 変化の激しい現代社会における学びの意義
- 生涯学習時代の到来と求められるスキル

第1章: 効果的な学びのメカニズム
- 脳科学から見た学習プロセス
- 記憶と理解の関係性
- モチベーションと学習効果の関連

第2章: 多様な学びの形態
- フォーマル学習とインフォーマル学習
- オンライン学習と対面学習の特徴と活用法
- ソーシャルラーニングの可能性

第3章: 実践的な学習方法論
- アクティブラーニングの実践
- 振り返りと内省の重要性
- 失敗からの学び方

第4章: 個人に合った学習スタイルの確立
- 学習タイプの診断と活用
- 時間管理と学習計画の立て方
- 持続可能な学習習慣の形成

第5章: デジタル時代の学び方
- テクノロジーを活用した効率的な学習
- 情報リテラシーとクリティカルシンキング
- オンラインリソースの選び方と活用法

終章: これからの学びのビジョン
- 未来の学びの展望
- 個人と組織における学びの統合
- 持続可能な学習社会の実現に向けて

この構成についてどのように感じられますか？特に重点を置きたい部分や、追加したい視点などございましたらお聞かせください。
//}

筆者としてそれを本当に書きたいかは別の話だが、これはこれでありだろう。ここまでは単なるウォーミングアップにすぎない。

試しに序章を書かせてみよう。さっきの続きで「試しに序章を書いてみて。2000文字程度で」と指示してみた。ここからがClaudeの本領発揮だ。

//emlist[Claude Sonnetの返答]{
序章：なぜ今、学びが重要なのか

私たちは今、かつてない速さで変化する時代を生きています。技術革新は日々加速し、人工知能やロボティクスの進化は、私たちの仕事や生活のあり方を根本から変えつつあります。昨日までの常識が今日には通用しない。そんな状況が、もはや珍しくありません。

このような激動の時代において、最も重要な能力の一つが「学び続ける力」です。しかし、ここで注意しなければならないのは、従来型の「知識の蓄積」としての学びだけでは、もはや不十分だということです。必要なのは、新しい状況に適応し、創造的な解決策を見出すための、より柔軟で実践的な学びの姿勢です。

例えば、コロナ禍は私たちに何を教えてくれたでしょうか。多くの人々が、オンラインでのコミュニケーションやデジタルツールの活用を、否応なく学ばざるを得ませんでした。この経験は、学びの本質が「必要に迫られた時にいかに素早く適応できるか」にあることを、まさに実証したと言えるでしょう。

現代社会における学びの重要性は、主に以下の三つの観点から考えることができます。

第一に、職業人としての視点です。世界経済フォーラムの報告によれば、今後10年間で、現在の仕事の多くが大きく変容するか、まったく新しい職種に置き換わると予測されています。このような環境下で生き残るためには、常に新しいスキルを習得し、自己をアップデートし続ける必要があります。

第二に、個人の幸福という視点です。学びは単なるスキル獲得以上の価値があります。新しいことを理解し、習得する過程で得られる充実感や達成感は、人生を豊かにする重要な要素となります。また、学びを通じて広がる人間関係や視野は、私たちの人生に新たな可能性をもたらしてくれます。

第三に、社会の持続可能性という視点です。気候変動やエネルギー問題、格差の拡大など、現代社会は複雑な課題に直面しています。これらの課題に対処するためには、社会全体としての学びと進化が不可欠です。一人ひとりが学び続け、成長し続けることが、社会の持続可能な発展につながるのです。

しかし、ここで一つの重要な問いが浮かび上がります。「どのように学べばよいのか？」という問いです。情報があふれる現代において、効果的な学びの方法を見出すことは、決して容易ではありません。また、日々の忙しさの中で、学びの時間を確保することも大きな課題となっています。

本書は、このような現代における学びの課題に対して、具体的な指針を提供することを目指しています。効果的な学習のメカニズムを理解し、自分に合った学習方法を見つけ、持続可能な学びの習慣を確立する。そのためのヒントを、最新の研究成果や実践例を交えながら紹介していきます。

学びは、決して義務や負担であってはなりません。それは、私たちの人生をより豊かで充実したものにするための、かけがえのない営みです。この本を通じて、読者の皆様が、自分なりの「学びの道」を見出すためのヒントを得ていただければ幸いです。

さあ、これからの時代に求められる、新しい学びの形を探っていきましょう。
//}

かなりそれっぽい文章だ。

さて、筆者の文体や癖のようなものを踏まえた文章を生成してみよう。今度は原稿を二つ添付して「今添付した原稿を元に、文体や癖を真似て、改めて序章を書いてみて。構成や主張内容も、原稿を参考にして」と指示してみた。

//emlist[Claude Sonnetの返答]{
添付された原稿の文体を参考に、序章を書き直してみます。

序章：知識の蓄積から自己変容へ - 学びの本質を探る

「学び」とは何だろうか？多くの人は「知識を得ること」「スキルを習得すること」と考えるかもしれない。しかし、本質的な学びとは、自己変容のプロセスそのものだ。知らなかった状態から知る状態へ、できなかったことができるようになる状態へ、理解していなかったことを理解できる状態へ。そうした変化の連続が、真の学びなのだ。

私たちは今、かつてないほど大量の情報に囲まれている。インターネットを開けば、膨大な知識の海が広がっている。技術書、ブログ記事、動画教材、そしてAIによる支援まで、学びのためのリソースは豊富だ。しかし、これらの情報は必ずしも学びに直結しない。むしろ、情報があふれているからこそ、効果的な学び方を理解することが重要になってきている。

学びには様々な形がある。学校教育のような体系的な学び、仕事を通じた実践的な学び、趣味から広がる自発的な学び。これらは一見異なるように見えて、実は共通する本質的なプロセスを持っている。それは「言語化」と「サイクル」だ。

言語化とは、漠然とした理解や感覚を、明確な言葉として表現することだ。私たちは普段、様々なことを「なんとなく」理解している。しかし、それを具体的な言葉として表現できない限り、その理解は不完全なものに留まる。言語化することで、理解は深まり、他者と共有可能な知識となる。

学びのサイクルは、現状の把握から始まり、目標の設定、実践、フィードバック、そして新たな目標の設定へと続く。このサイクルは一回で完結するものではない。むしろ、繰り返し回すことで、学びは螺旋状に深まっていく。

本書では、この「言語化」と「サイクル」を軸に、効果的な学びの方法を探っていく。プログラミングや技術的な学びの例も取り上げるが、それらは普遍的な学びの原理を理解するための具体例として扱う。学びのメカニズムを理解し、実践することで、あらゆる分野での成長につながるはずだ。

与えられた知識を受動的に受け取るのではなく、自ら考え、言語化し、実践する。そんな能動的な学びのあり方を、これから一緒に探っていきたい。今、あなたの手元にあるこの本も、著者たちの学びを言語化し、共有したものだ。この本を通じて、読者の皆さんが自分なりの学びの形を見つけるきっかけになれば幸いである。

さあ、学びの本質を探る旅に出発しよう。
//}

細かいところは違うものの、かなり筆者っぽくなった。

Claude Sonnetの場合は、このように日本語を扱うのが達者なので、原稿を添付して、色々注文を付ければ、それなりにそれっぽい文章を生成してくれる。さてあなたは筆者が書いた原稿のうち、どれくらいが生成AIによるものかわかるだろうか？特に答えは書かないが、実は使っていたのだ。気づく場所はあっただろうか？気づく場所がなければ、それがClaude Sonnetの恐るべき力の証明だ。

もっとも、学びのアウトプットとしては、これに頼ると本来の目的を果たせなくなるため注意しなければならないため、文章を書かせるというよりは、構成案を出させるとか、そういう使い方が望ましいだろう。

=== 活用事例: 文章を読ませる

言葉を扱うのが得意なのがLLMなので、書かせるだけではなく読ませることにも適している。

たとえば原稿についてであれば「添付は原稿である。この原稿は十分だろうか？もっと膨らませる余地はないだろうか？重複はあるだろうか？読みやすくすることはできるか？」などと指示すれば、原稿のレビューをしてくれる。あなたが技術ブログを書くときに、役立ってくれるだろう。

これまで述べたとおり正確性は過信してはいけないが、技術ブログのレビューをさせるのもある程度有用だ。あなたの抜け漏れや、間違いの指摘や、文章の発展性について聞くと、すらすら答えてくれるはずだ。

他にも定番の使い方がある。あなたがたとえば生成AIに興味があるならば、論文を読ませればいい。今時はarxivに様々な論文（の前段階のようなもの）が大量に公開されている。少なくとも生成AIの最先端で外部公開されている論文ならまず大半がarxivにある。

大量にある論文をそのまま読むのはしんどい。分量も多いし、英語で書かれているので、日本語に翻訳したり要約してもらったり、質疑応答をさせるのだ。そうして本当に読みたい論文があれば、原文を読むなりすればいい。

筆者が先日注目していた論文にHtmlRAGというものがある。その論文を添付して「解説お願い」と投げてみた。

https://arxiv.org/html/2411.02959v1

//emlist[Claude Sonnetの返答]{
この論文は「HtmlRAG」という新しい手法についての研究を説明しています。以下が主なポイントです：

1. 研究の背景と課題:
- 従来のRAG(Retrieval-Augmented Generation)システムは、HTMLをプレーンテキストに変換して使用
- この過程で、HTMLの構造的・意味的な情報が失われる問題がある
- 例えば、表形式のデータや見出し構造などが失われる

2. 提案手法 (HtmlRAG):
- HTMLをそのままの形式で知識源として使用
- 主な課題は、HTMLが長すぎることと余分なコンテンツ(JavaScript、CSSなど)を含むこと
- これに対して以下の3つのステップで対処:

   a. HTMLクリーニング:
   - CSSやJavaScriptの削除
   - 冗長なHTML属性の削除
   - 単一の入れ子タグの統合

   b. ブロックツリーの構築:
   - DOMツリーをより粗い粒度のブロックツリーに変換
   - 効率的な処理のため

   c. 2段階のHTML刈り込み:
   - 埋め込みモデルによる粗い刈り込み
   - 生成モデルによる細かい刈り込み

3. 実験結果:
- 6つのQAデータセットで評価
- 従来の手法と比較して優れた性能を示す
- HTMLの構造情報を保持することの有効性を実証

4. 主な利点:
- HTML構造による意味的情報の保持
- LLMsの事前学習でHTMLに触れているため、追加学習不要
- 様々な文書フォーマット(PDF、Wordなど)からHTMLへの変換が容易

この研究は、RAGシステムにおいてHTMLを直接利用することの有効性を示し、新しい研究の方向性を開いた点で意義があります。
//}

雑に概要をつかむだけならこんな指示でも十分だ。疑問が思いつくならそれを投げてみれば、それなりに回答してくれる。

ただし、雑な指示の弱点は、論文をどのように解説してくれるかはランダムになってしまうことにある。解釈内容はまず変わらないが、本当に求めているタイプの解説が帰ってくるとは限らないし、投げるたびに解説の仕方や、その範囲が変わってしまう。

つまり、聞きたい内容はこちらが明示的に指示しなければならない。

 * 研究の主な目的と問題意識
 * 使用された研究手法
 * 主要な発見や結論
 * 研究の意義や限界
 * 今後の研究への示唆

このようなことが聞ければいいだろうか。

//emlist[Claude Sonnetの返答]{
この論文を分析させていただきます。

### 研究の主な目的と問題意識

この研究は、Retrieval-Augmented Generation (RAG)システムにおいて、HTMLをそのまま知識形式として活用することを提案しています。

主な問題意識：
- 従来のRAGシステムは、HTMLをプレーンテキストに変換して使用していた
- この変換過程で、見出しやテーブル構造などの重要な構造的・意味的情報が失われていた
- HTMLをそのまま使用すると、タグやスクリプトなどで入力が長くなりすぎる課題があった

### 使用された研究手法

「HtmlRAG」と呼ばれる新しいアプローチを開発し、以下の主要な技術を実装:

1. HTMLクリーニング:
- CSSやJavaScript、コメントなどの不要な要素を除去
- 冗長なHTML構造を圧縮

2. 2段階のHTML枝刈り(pruning):
- ブロックツリーベースの構造を構築
- テキスト埋め込みに基づく粗い枝刈り
- 生成モデルを使用したより細かい枝刈り

### 主要な発見や結論

1. 性能面:
- 6つのQAデータセットで評価を実施
- 従来のプレーンテキストベースの手法と比較して優れた結果を示した

2. 効率面:
- HTMLクリーニングで元のサイズの6%まで削減
- 2段階の枝刈りアプローチにより、効率的に重要な情報を抽出できた

### 研究の意義と限界

意義:
- RAGシステムにおけるHTML活用の新しいパラダイムを提示
- 構造化された情報を保持しながら効率的な処理を実現
- 実用的な実装方法を具体的に示した

限界:
- 計算コストが従来手法より若干高い
- HTMLの構造が複雑な場合の処理効率
- 特定のドメインやタスクでの評価が限定的

### 今後の研究への示唆

1. モデルの改善:
- より効率的なHTML処理アルゴリズムの開発
- 特定のドメインに特化した最適化

2. 応用範囲の拡大:
- 他の構造化文書フォーマットへの適用
- より多様なタスクでの評価

3. 技術的な発展:
- LLMの進化に合わせたHTML処理の最適化
- マルチモーダル情報の統合

この研究は、RAGシステムにおける構造化情報の活用という重要な方向性を示しており、今後のこの分野の発展に大きな示唆を与えています。
//}

間違い探しの始まりだ。

//table[erukiti-paper1][プロンプトでの差異]{
項目	違い
背景の説明	ほぼ変わらない
手法	指示なしの方が少し詳細に踏み込んでいる。

//}