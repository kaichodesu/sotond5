PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//520772/1061851/2.49/4/4/Schottky Diode

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r80_90"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.900) (shapeHeight 0.800))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(padStyleDef "r120_90"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.900) (shapeHeight 1.200))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Normal"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 1.27)
			(strokeWidth 0.127)
		)
	)
	(patternDef "BF998215" (originalName "BF998215")
		(multiLayer
			(pad (padNum 1) (padStyleRef r120_90) (pt -0.800, -0.625) (rotation 90))
			(pad (padNum 2) (padStyleRef r80_90) (pt 1.000, -0.625) (rotation 90))
			(pad (padNum 3) (padStyleRef r80_90) (pt 1.000, 1.375) (rotation 90))
			(pad (padNum 4) (padStyleRef r80_90) (pt -1.000, 1.375) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0.000, 0.225) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.45 1.025) (pt 1.45 1.025) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.45 1.025) (pt 1.45 -0.275) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.45 -0.275) (pt -1.45 -0.275) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.45 -0.275) (pt -1.45 1.025) (width 0.025))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.45 2.825) (pt 2.45 2.825) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 2.45 2.825) (pt 2.45 -2.375) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 2.45 -2.375) (pt -2.45 -2.375) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.45 -2.375) (pt -2.45 2.825) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.45 0.775) (pt -1.45 -0.025) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 1.45 0.775) (pt 1.45 -0.025) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 1.45 -0.025) (pt 1.45 -0.025) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -0.4 1.025) (pt 0.4 1.025) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 0 -0.275) (pt 0.4 -0.275) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -0.9 -1.325) (pt -0.9 -1.325) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -0.85, -1.325) (radius 0.05) (startAngle 180.0) (sweepAngle -180.0) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -0.8 -1.325) (pt -0.8 -1.325) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -0.85, -1.325) (radius 0.05) (startAngle .0) (sweepAngle -180.0) (width 0.1))
		)
	)
	(symbolDef "BAS3007ARPPE6327HTSA1" (originalName "BAS3007ARPPE6327HTSA1")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 3) (pt 1000 mils -100 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 770 mils -125 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 4) (pt 1000 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 770 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(line (pt 200 mils 100 mils) (pt 800 mils 100 mils) (width 6 mils))
		(line (pt 800 mils 100 mils) (pt 800 mils -200 mils) (width 6 mils))
		(line (pt 800 mils -200 mils) (pt 200 mils -200 mils) (width 6 mils))
		(line (pt 200 mils -200 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 850 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 850 mils 200 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "BAS3007ARPPE6327HTSA1" (originalName "BAS3007ARPPE6327HTSA1") (compHeader (numPins 4) (numParts 1) (refDesPrefix D)
		)
		(compPin "1" (pinName "-") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "2" (pinName "~_1") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "3" (pinName "~_2") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "4" (pinName "+") (partNum 1) (symPinNum 4) (gateEq 0) (pinEq 0) (pinType Unknown))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "BAS3007ARPPE6327HTSA1"))
		(attachedPattern (patternNum 1) (patternName "BF998215")
			(numPads 4)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
				(padNum 4) (compPinRef "4")
			)
		)
		(attr "Mouser Part Number" "726-BAS3007A-RPPE6")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/Infineon-Technologies/BAS3007ARPPE6327HTSA1?qs=OwbwYO03UsIpevUvLWxseg%3D%3D")
		(attr "Manufacturer_Name" "Infineon")
		(attr "Manufacturer_Part_Number" "BAS3007ARPPE6327HTSA1")
		(attr "Description" "Infineon BAS3007ARPPE6327HTSA1 SMT Schottky Diode, 30V 900mA, 4-Pin SOT-143")
		(attr "<Hyperlink>" "https://www.mouser.co.uk/datasheet/2/196/Infineon-BAS3007ASERIES-DS-v01_01-en-1225497.pdf")
		(attr "<STEP Filename>" "BAS3007ARPPE6327HTSA1.stp")
		(attr "<STEP Offsets>" "X=0;Y=0.55;Z=0.6")
		(attr "<STEP Rotation>" "X=0;Y=0;Z=0")
	)

)
