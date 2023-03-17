PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//1066347/1061851/2.49/3/4/MOSFET P-Channel

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r285_125"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.250) (shapeHeight 2.850))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(padStyleDef "r650_550"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 5.500) (shapeHeight 6.500))
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
	(patternDef "FDD8874" (originalName "FDD8874")
		(multiLayer
			(pad (padNum 1) (padStyleRef r285_125) (pt -2.280, -3.240) (rotation 0))
			(pad (padNum 2) (padStyleRef r650_550) (pt 0.000, 3.160) (rotation 0))
			(pad (padNum 3) (padStyleRef r285_125) (pt 2.280, -3.240) (rotation 0))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0.000, 0.635) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt -3.365 5.14) (pt 3.365 5.14) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 3.365 5.14) (pt 3.365 -1.08) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 3.365 -1.08) (pt -3.365 -1.08) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -3.365 -1.08) (pt -3.365 5.14) (width 0.025))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -4.365 7.41) (pt 4.365 7.41) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 4.365 7.41) (pt 4.365 -6.14) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 4.365 -6.14) (pt -4.365 -6.14) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -4.365 -6.14) (pt -4.365 7.41) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -3.365 5.14) (pt -3.365 -1.08) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -3.365 -1.08) (pt 3.365 -1.08) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 3.365 -1.08) (pt 3.365 5.14) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -2.4 -5.04) (pt -2.4 -5.04) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -2.3, -5.04) (radius 0.1) (startAngle 180.0) (sweepAngle 180.0) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -2.2 -5.04) (pt -2.2 -5.04) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -2.3, -5.04) (radius 0.1) (startAngle .0) (sweepAngle 180.0) (width 0.2))
		)
	)
	(symbolDef "FQD2P40TM" (originalName "FQD2P40TM")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 0 mils -45 mils) (rotation 0]) (justify "UpperLeft") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 300 mils 400 mils) (rotation 270) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 305 mils 400 mils) (rotation 90]) (justify "UpperLeft") (textStyleRef "Normal"))
		))
		(pin (pinNum 3) (pt 300 mils -200 mils) (rotation 90) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 305 mils -200 mils) (rotation 90]) (justify "LowerLeft") (textStyleRef "Normal"))
		))
		(line (pt 300 mils 100 mils) (pt 300 mils -100 mils) (width 6 mils))
		(line (pt 300 mils 200 mils) (pt 300 mils 300 mils) (width 6 mils))
		(line (pt 100 mils 0 mils) (pt 200 mils 0 mils) (width 6 mils))
		(line (pt 200 mils 0 mils) (pt 200 mils 200 mils) (width 6 mils))
		(line (pt 300 mils 100 mils) (pt 230 mils 100 mils) (width 6 mils))
		(line (pt 300 mils 200 mils) (pt 230 mils 200 mils) (width 6 mils))
		(line (pt 230 mils 0 mils) (pt 300 mils 0 mils) (width 6 mils))
		(line (pt 230 mils 220 mils) (pt 230 mils 180 mils) (width 6 mils))
		(line (pt 230 mils -20 mils) (pt 230 mils 20 mils) (width 6 mils))
		(line (pt 230 mils 80 mils) (pt 230 mils 120 mils) (width 6 mils))
		(arc (pt 250 mils 100 mils) (radius 150 mils) (startAngle 0) (sweepAngle 360) (width 10  mils))
		(poly (pt 300 mils 100 mils) (pt 260 mils 120 mils) (pt 260 mils 80 mils) (pt 300 mils 100 mils) (width 10  mils))
		(attr "RefDes" "RefDes" (pt 450 mils 150 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 450 mils 50 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "FQD2P40TM" (originalName "FQD2P40TM") (compHeader (numPins 3) (numParts 1) (refDesPrefix Q)
		)
		(compPin "1" (pinName "G") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "D") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "S") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "FQD2P40TM"))
		(attachedPattern (patternNum 1) (patternName "FDD8874")
			(numPads 3)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
			)
		)
		(attr "Manufacturer_Name" "onsemi")
		(attr "Manufacturer_Part_Number" "FQD2P40TM")
		(attr "Mouser Part Number" "512-FQD2P40TM")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/onsemi-Fairchild/FQD2P40TM?qs=wg6chLqwgwqz4IFYQILlYg%3D%3D")
		(attr "Arrow Part Number" "FQD2P40TM")
		(attr "Arrow Price/Stock" "https://www.arrow.com/en/products/fqd2p40tm/on-semiconductor?region=nac")
		(attr "Mouser Testing Part Number" "")
		(attr "Mouser Testing Price/Stock" "")
		(attr "Description" "MOSFET QF -400V 6.5OHM DPAK")
		(attr "<Hyperlink>" "https://www.onsemi.com/pub/Collateral/FQD2P40-D.pdf")
		(attr "<STEP Filename>" "FQD2P40TM.stp")
		(attr "<STEP Offsets>" "X=0;Y=1.45;Z=2.51")
		(attr "<STEP Rotation>" "X=0;Y=180;Z=0")
	)

)
