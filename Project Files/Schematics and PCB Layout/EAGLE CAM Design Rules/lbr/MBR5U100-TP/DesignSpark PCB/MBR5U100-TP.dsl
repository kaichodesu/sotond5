SamacSys ECAD Model
16462684/1061851/2.49/3/3/Schottky Diode

DESIGNSPARK_INTERMEDIATE_ASCII

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "s140"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.400) (shapeHeight 1.400))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(padStyleDef "r486_336"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 3.360) (shapeHeight 4.860))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Default"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 50 mils)
			(strokeWidth 5 mils)
		)
	)
	(patternDef "MBR5U100TP" (originalName "MBR5U100TP")
		(multiLayer
			(pad (padNum 1) (padStyleRef s140) (pt -2.855, -0.920) (rotation 90))
			(pad (padNum 2) (padStyleRef s140) (pt -2.855, 0.920) (rotation 90))
			(pad (padNum 3) (padStyleRef r486_336) (pt 1.125, 0.000) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0.000, 0.000) (textStyleRef "Default") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt -2.7 -2) (pt 2.7 -2) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 2.7 -2) (pt 2.7 2) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 2.7 2) (pt -2.7 2) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -2.7 2) (pt -2.7 -2) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt -4.555 -3) (pt 4.555 -3) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt 4.555 -3) (pt 4.555 3) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt 4.555 3) (pt -4.555 3) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt -4.555 3) (pt -4.555 -3) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -2.6 2) (pt 2.7 2) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -2.7 -2) (pt 2.7 -2) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -4 -1) (pt -4 -1) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -4, -0.95) (radius 0.05) (startAngle 270) (sweepAngle 180.0) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -4 -0.9) (pt -4 -0.9) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -4, -0.95) (radius 0.05) (startAngle 90.0) (sweepAngle 180.0) (width 0.1))
		)
	)
	(symbolDef "MBR5U100-TP" (originalName "MBR5U100-TP")

		(pin (pinNum 1) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 2) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 3) (pt 1800 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1570 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(line (pt 200 mils 100 mils) (pt 1600 mils 100 mils) (width 6 mils))
		(line (pt 1600 mils 100 mils) (pt 1600 mils -200 mils) (width 6 mils))
		(line (pt 1600 mils -200 mils) (pt 200 mils -200 mils) (width 6 mils))
		(line (pt 200 mils -200 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 1650 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Default"))

	)
	(compDef "MBR5U100-TP" (originalName "MBR5U100-TP") (compHeader (numPins 3) (numParts 1) (refDesPrefix D)
		)
		(compPin "1" (pinName "ANODE_1") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "ANODE_2") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "COMMON CATHODE") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "MBR5U100-TP"))
		(attachedPattern (patternNum 1) (patternName "MBR5U100TP")
			(numPads 3)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
			)
		)
		(attr "Manufacturer_Name" "MCC")
		(attr "Manufacturer_Part_Number" "MBR5U100-TP")
		(attr "Mouser Part Number" "")
		(attr "Mouser Price/Stock" "")
		(attr "Arrow Part Number" "")
		(attr "Arrow Price/Stock" "")
		(attr "Mouser Testing Part Number" "")
		(attr "Mouser Testing Price/Stock" "")
		(attr "Description" "Diode Schottky 100 V 5A Surface Mount TO-277")
		(attr "Datasheet Link" "https://www.mccsemi.com/pdf/Products/MBR5U100(TO-277).pdf")
		(attr "Height" "1.2 mm")
	)

)
