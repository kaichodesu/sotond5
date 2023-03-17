PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//11368662/1061851/2.49/2/5/Resistor

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r180_120"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.2) (shapeHeight 1.8))
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
	(patternDef "RESC3216X75N" (originalName "RESC3216X75N")
		(multiLayer
			(pad (padNum 1) (padStyleRef r180_120) (pt -1.5, 0) (rotation 0))
			(pad (padNum 2) (padStyleRef r180_120) (pt 1.5, 0) (rotation 0))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.35 1.15) (pt 2.35 1.15) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 2.35 1.15) (pt 2.35 -1.15) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 2.35 -1.15) (pt -2.35 -1.15) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.35 -1.15) (pt -2.35 1.15) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.6 0.8) (pt 1.6 0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.6 0.8) (pt 1.6 -0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.6 -0.8) (pt -1.6 -0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.6 -0.8) (pt -1.6 0.8) (width 0.025))
		)
		(layerContents (layerNumRef 18)
			(line (pt 0 0.7) (pt 0 -0.7) (width 0.2))
		)
	)
	(symbolDef "CR1206-FX-6491ELF" (originalName "CR1206-FX-6491ELF")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 0 mils -35 mils) (rotation 0]) (justify "UpperLeft") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 700 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 700 mils -35 mils) (rotation 0]) (justify "UpperRight") (textStyleRef "Normal"))
		))
		(line (pt 200 mils 50 mils) (pt 500 mils 50 mils) (width 6 mils))
		(line (pt 500 mils 50 mils) (pt 500 mils -50 mils) (width 6 mils))
		(line (pt 500 mils -50 mils) (pt 200 mils -50 mils) (width 6 mils))
		(line (pt 200 mils -50 mils) (pt 200 mils 50 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 550 mils 250 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 550 mils 150 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "CR1206-FX-6491ELF" (originalName "CR1206-FX-6491ELF") (compHeader (numPins 2) (numParts 1) (refDesPrefix R)
		)
		(compPin "1" (pinName "1") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "2" (pinName "2") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Unknown))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "CR1206-FX-6491ELF"))
		(attachedPattern (patternNum 1) (patternName "RESC3216X75N")
			(numPads 2)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
			)
		)
		(attr "Mouser Part Number" "652-CR1206FX-6491ELF")
		(attr "Mouser Price/Stock" "https://www.mouser.com/Search/Refine.aspx?Keyword=652-CR1206FX-6491ELF")
		(attr "Manufacturer_Name" "Bourns")
		(attr "Manufacturer_Part_Number" "CR1206-FX-6491ELF")
		(attr "Description" "Thick Film Resistors - SMD 6.49K 1%")
		(attr "<Hyperlink>" "https://componentsearchengine.com/Datasheets/1/CR1206-FX-6491ELF.pdf")
		(attr "<Component Height>" "0.75")
		(attr "<STEP Filename>" "CR1206-FX-6491ELF.stp")
		(attr "<STEP Offsets>" "X=0;Y=0;Z=0")
		(attr "<STEP Rotation>" "X=0;Y=0;Z=0")
	)

)
