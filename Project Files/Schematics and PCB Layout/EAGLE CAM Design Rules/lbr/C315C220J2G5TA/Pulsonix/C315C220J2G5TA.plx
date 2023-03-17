PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//167982/1061851/2.49/2/2/Capacitor

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "c121_h71"
		(holeDiam 0.71)
		(padShape (layerNumRef 1) (padShapeType Ellipse)  (shapeWidth 1.21) (shapeHeight 1.21))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 1.21) (shapeHeight 1.21))
	)
	(textStyleDef "Normal"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 1.27)
			(strokeWidth 0.127)
		)
	)
	(patternDef "C315" (originalName "C315")
		(multiLayer
			(pad (padNum 1) (padStyleRef c121_h71) (pt -1.27, 0) (rotation 90))
			(pad (padNum 2) (padStyleRef c121_h71) (pt 1.27, 0) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt -0.308, 0.057) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.905 1.57) (pt 1.905 1.57) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.905 1.57) (pt 1.905 -1.57) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.905 -1.57) (pt -1.905 -1.57) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.905 -1.57) (pt -1.905 1.57) (width 0.025))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.905 1.57) (pt 1.905 1.57) (width 0.254))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.905 -1.57) (pt 1.905 -1.57) (width 0.254))
		)
	)
	(symbolDef "C315C220J2G5TA" (originalName "C315C220J2G5TA")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 0 mils -35 mils) (rotation 0]) (justify "UpperLeft") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 500 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 500 mils -35 mils) (rotation 0]) (justify "UpperRight") (textStyleRef "Normal"))
		))
		(line (pt 220 mils 100 mils) (pt 220 mils -100 mils) (width 6 mils))
		(line (pt 280 mils 100 mils) (pt 280 mils -100 mils) (width 6 mils))
		(line (pt 200 mils 0 mils) (pt 220 mils 0 mils) (width 6 mils))
		(line (pt 280 mils 0 mils) (pt 300 mils 0 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 350 mils 250 mils) (justify 24) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 350 mils 150 mils) (justify 24) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "C315C220J2G5TA" (originalName "C315C220J2G5TA") (compHeader (numPins 2) (numParts 1) (refDesPrefix C)
		)
		(compPin "1" (pinName "1") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "2" (pinName "2") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Unknown))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "C315C220J2G5TA"))
		(attachedPattern (patternNum 1) (patternName "C315")
			(numPads 2)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
			)
		)
		(attr "Mouser Part Number" "80-C315C220J2G")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/KEMET/C315C220J2G5TA?qs=6DDjpUaD9G3WE9%2F2Ct37CQ%3D%3D")
		(attr "Manufacturer_Name" "KEMET")
		(attr "Manufacturer_Part_Number" "C315C220J2G5TA")
		(attr "Description" "GoldMax 300 Comm C0G, Ceramic, 22 pF, 5%, 200 VDC, 500 VDC, 125C, -55C, C0G, GoldMax, Commercial Standard, 0.1 % , 100 GOhms, 3.81mm, 3.14mm, 2.54mm, Lead Spacing = 2.54mm, 7mm, 0.51mm, 500, 120")
		(attr "<Hyperlink>" "https://content.kemet.com/datasheets/KEM_C1049_GOLDMAX_C0G.pdf")
		(attr "<Component Height>" "3.14")
		(attr "<STEP Filename>" "C315C220J2G5TA.stp")
		(attr "<STEP Offsets>" "X=1.9;Y=1.27;Z=0")
		(attr "<STEP Rotation>" "X=90;Y=0;Z=0")
	)

)
